#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
#define f first
#define s second
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
ll dp[300005], n, m;

int main(){
	ll i, j;
	cin >> n >> m;
	if(n>m)swap(n,m);
	j = n+m;
	if(n == m){
		dp[1] = m;
		m--;
		for(i=2;i<=j;i++){
			if(i%2==0){
				dp[i] = n*dp[i-1]; n--;
			}else {
				dp[i] = m*dp[i-1]; m--;
			}dp[i]%=mod;
		}
		dp[j]*=2;
	}else if(m-1==n){
		dp[1] = m;
		m--;
		for(i=2;i<=j;i++){
			if(i%2==0){
				dp[i] = n*dp[i-1]; n--;
			}else {
				dp[i] = m*dp[i-1]; m--;
			}dp[i]%=mod;
		}
	}
	cout << dp[j]%mod;
}
