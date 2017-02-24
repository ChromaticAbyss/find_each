#pragma once

#include <vector>
#include <list>


/*
find_each
arguments: Beginning and ending iterator to two (parts of) containers you want to pattern match on, optional: bool allow overlapping matches
result: std::vector of iterators on the first container, each marking the beginning of a match
time: linear in the length of the longer input
*/

//TODO: Template Parameter 2) Type for collection of return values (defaults to vector, can be anything that supports emplace_back)  

namespace find_each {

	
	template<typename T> void MakePrefixFct(T s_begin, T s_end, std::vector<int>& prefix_fct_jump, std::vector<T>& prefix_fct) {
		auto count = std::distance(s_begin,s_end);

		prefix_fct_jump.reserve(count);
		prefix_fct.reserve(count);

		prefix_fct_jump.push_back(0);
		prefix_fct.push_back(s_begin);

		T s_run(s_begin);
		s_run++;//Start iteration at second element

		int k = 0; //Counts matching prefix
		T k_run(s_begin); //P[k+1]

		while (s_run != s_end) {
			while (k > 0 && *(k_run) != *s_run) {
				k_run = prefix_fct[k - 1];
				k = prefix_fct_jump[k - 1];
			}


			if (*(k_run) == *s_run) {
				k++;
				k_run++;
			}

			prefix_fct_jump.emplace_back(k);
			prefix_fct.emplace_back(k_run);

			s_run++;
		}
	};

	template<typename TL, typename TS, typename ContainerT = std::vector<TL>> ContainerT find_each(TL l_begin, TL l_end, TS s_begin, TS s_end, bool overlap_matches = true) { //T some kind of forward iterator
		ContainerT matches;//Our results

		//Make prefix function
		std::vector<int> prefix_fct_jump;
		std::vector<TS> prefix_fct;
		MakePrefixFct<TS>(s_begin, s_end, prefix_fct_jump, prefix_fct);
		size_t prefix_fct_size = prefix_fct.size();

		//List drop backlog is the element of the long string that was active m iterations ago,
		//or l_end if we aren't at least m elements in
		TL backlog(l_end);


		TL l_run(l_begin); //Iterator on long string
		unsigned int i = 0; //pos on long string as int

		TS s_run(s_begin); //pos on short string
		unsigned int q = 0; //current match length (=pos on short string as int)

		while (l_run != l_end) {
			//Keep a log of recent iterators to be able to output the beginnings of matches
			if (i == prefix_fct_size - 1) {
				backlog = l_begin;
			}
			if (i >= prefix_fct_size) {
				backlog++;
			}


			//On a mismatch reduce until we hit the longest matching prefix or nothing matches(q=0)
			while (q > 0 && *s_run != *l_run) {
				//cout << "miss" << endl;
				//cout << "s_run " << *s_run << " l_run " << *l_run << endl;
				s_run = prefix_fct[q - 1];
				q = prefix_fct_jump[q - 1];
			}

			//Count up length of match
			if (*s_run == *l_run) {
				s_run++;
				q++;
			}

			//On a match push the first element of the backlog as a result, reduce to the next highest matching prefix
			//We allow matches to overlap!
			if (s_run == s_end) {
				//matches.emplace_back(backlog.front());
				matches.push_back(backlog);

				if (overlap_matches) {
					s_run = prefix_fct[prefix_fct_size - 1]; //If we allow overlapping matches we might not need to go all the way back.
					q = prefix_fct_jump[prefix_fct_size - 1];
				}
				else {
					s_run = s_begin; //Complete reset if we don't want overlapping matches
					q = 0;
				}
			}


			i++;
			l_run++;
		}


		return matches;
	};


};