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


	int i = 0;

	auto res = find_each::find_each(a.cbegin(),a.cend(),b.cbegin(),b.cend(),true); //<std::vector<int>::iterator, std::vector<float>::iterator,std::vector<int>>
	cout << '#' << res.size()<<endl;
	for (int i = 0; i < res.size(); i++) {
		cout << *res[i] << endl;
	}



	system("pause");
}

