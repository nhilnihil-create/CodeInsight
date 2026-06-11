#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

bool isOK(string &s){
	int n = s.size()/2;
	for(int i = 0;i < n;i++){
		if(s[i] != s[i+n]) return false;
	}
	return true;
}

signed main(){
	string s;
	cin >> s;
	while(1){
		s.pop_back();
		s.pop_back();
		if(isOK(s)){
			cout << s.size() << endl;
			break;
		}
	}

	return 0;
}
