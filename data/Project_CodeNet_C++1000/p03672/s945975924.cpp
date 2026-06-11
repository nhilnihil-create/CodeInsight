#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool f(string s){
	int len = s.size();
	if(len % 2 == 1) return false;
	for(int i = 0;i < len/2;i++){
		if(s[i] != s[i+len/2]) return false;
	}
	return true;
}

int main(){
	string s;
	cin >> s;
	int len = s.size();
	rep(i,len){
		s.pop_back();
		if(f(s)){
			int ans = s.size();
			cout << ans;
			return 0;
		}
	}
}