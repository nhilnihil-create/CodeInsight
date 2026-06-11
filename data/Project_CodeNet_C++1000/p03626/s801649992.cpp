#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n;cin>>n;
	string s1,s2;cin>>s1>>s2;
	for(int i = 1; i < s1.size(); i++) {
		if (s1[i - 1] == s1[i]){
			s1.erase(s1.begin() + i - 1);
		}
		if (s2[i - 1] == s2[i]){
			s2.erase(s2.begin() + i - 1);
		}
	}

	vector<ll> dp(n + 1,0LL);
	if (s1[0] == s2[0]){
		dp[0] = 3;
	}
	else{
		dp[0] = 6;
	}
	for(int i = 1; i < s1.size(); i++) {
		if (s1[i] == s2[i]){
			if(s1[i - 1] == s2[i - 1]){
				dp[i] = 2LL * dp[i - 1];
			}
			else{
				dp[i] = dp[i - 1];
			}
		}
		else{
			if (s1[i - 1] == s2[i - 1]){
				dp[i] = 2LL * dp[i - 1];
			}
			else{
				dp[i] = 3LL * dp[i - 1];
			}
		}
		dp[i] %= mod;
	}
	cout << dp[s1.size() - 1] << endl;
	return 0;
}