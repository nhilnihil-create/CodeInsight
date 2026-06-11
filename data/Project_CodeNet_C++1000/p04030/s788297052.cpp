#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	list<char> li;
	for(char c: s) {
		if(c == 'B') {
			if(li.size() > 0) li.pop_back();
		} else {
			li.push_back(c);
		}
	}
	for(char c: li) cout << c;
}
