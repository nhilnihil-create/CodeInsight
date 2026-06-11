#include <iostream>
#include<unordered_set>
using namespace std;
int main()
{
	string s;
	cin >> s;
	unordered_multiset<char> ms;
	for(const auto& i : s) ms.insert(i);
	for(const auto& i : ms) 
	  if(ms.count(i) > 1) {
	  	cout << "no";
	  	return 0;
	  }
	  cout << "yes";
	return 0;
}