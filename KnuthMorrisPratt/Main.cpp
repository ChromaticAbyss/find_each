#include <iostream>
#include <string>

#include <list>

#include <algorithm>

#include "KMP.h"
#include "Main.h"

using namespace std;

int main() {

	string a = "aababab";
	string b = "abab";
	/*
	vector<float>  a;
	for (int i = 0; i < 50; i++) {
		a.push_back( i%5);
	}
	vector<float> b;
	for (int i = 0; i < 10; i++) {
		b.push_back( i % 5 );
	}
	*/
	int i = 0;

	auto res = find_each::find_each(a.cbegin(),a.cend(),b.cbegin(),b.cend(),true); //<std::vector<int>::iterator, std::vector<float>::iterator,std::vector<int>>
	cout << "#" << res.size()<<endl;
	for (int i = 0; i < res.size(); i++) {
		cout << *res[i] << endl;
	}

/*
  i = 1;
  vector<vector<float>::const_iterator> test;
  vector<float>::const_iterator al = a.cbegin();
  while (al != a.cend()) {
	  auto res2 = search(al, a.cend(), b.cbegin(), b.cend());
	  
	  if (res2 == a.cend()) { break; }
	  else { test.push_back(res2); al = res2; al++; }
  }


	 i = 2;
	 */
	 //Test output to see if we really have the proper spots
	 //cout << res.size() << "|" << test.size() << endl; //  << " | " << res2.size();


	system("pause");
}

