#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

string t = "bcdefghijklmnopqrstuvwxyza";
string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(){
	string s;
	cin >> s;
	ll k;
	cin >> k;
	map<char,int> mp;
	map<char,int> alpha;
	rep(i,26){
		mp[t[i]] = 25-i;
		alpha[alphabet[i]] = i;
	}
	
	string ans;
	ll count = k;
	rep(i,s.size()-1){
		if(mp[s[i]] <= count){
			ans.push_back('a');
			count -= mp[s[i]];
		}else{
			ans.push_back(s[i]);
		}
	}
	
	ans.push_back(alphabet[(alpha[s[s.size()-1]]+count)%26]);
	
	cout << ans << endl;
	
    return 0;
}

