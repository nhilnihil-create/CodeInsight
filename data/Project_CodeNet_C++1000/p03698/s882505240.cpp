#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	map<char,int> mp;
	int len = s.size();
	rep(i,len){
		mp[s[i]]++;
		if(mp[s[i]] == 2){
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;
}