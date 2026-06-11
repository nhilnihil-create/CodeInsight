#include <bits/stdc++.h>
using namespace std;
int main() {
	// #ifndef ONLINE_JUDGE
	// 	// for getting input from input.txt
	// 	freopen("input.txt", "r", stdin);
	// 	// for writing output to output.txt
	// 	freopen("output.txt", "w", stdout);
	// #endif
	string s,t;
	cin>>s;
	t = s;
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	if(s.size() == t.size()) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
    }
	