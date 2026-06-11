#include<bits/stdc++.h>
using namespace std;


int main()
{
	string s; cin >> s;
	regex r ("(dream|dreamer|erase|eraser)*");
	cout << ((regex_match(s, r)) ? "YES" : "NO") << endl;
}

