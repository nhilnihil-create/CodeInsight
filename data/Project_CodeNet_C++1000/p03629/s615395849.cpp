#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	ll n = s.size();
	
	string dp[26];
	zep(j, 0, 26){dp[j] = j+'a';}
	
	zep(i, 0, n){
		string a = s.substr(i, 1);
		string ms = dp[0]+a;

		zep(j, 1, 26){
			string tmp = dp[j]+a;
			if(tmp.size() < ms.size() || (tmp.size() == ms.size() && tmp < ms)){
				ms = dp[j]+a;
			}
		}
		dp[s[i]-'a'] = ms;
	}
	
	string ans = dp[0];
	zep(j, 1, 26){
		if(dp[j].size() < ans.size() || (dp[j].size() == ans.size() && dp[j] < ans)){
			ans = dp[j];
		}
	}
	print(ans)
	return 0;
}