#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P std::pair<int,int>
#define PiP std::pair<int,std::pair<int,int>>
#define all(v) v.begin(),v.end()
#define mkp std::make_pair
#define prique(T) std::priority_queue<T,vector<T>,greater<T>>
using namespace std;
template<class T> inline void chmax(T& a, T b) { a = std::max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = std::min(a, b); }

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}
int get_rand(int MIN, int MAX) {
	std::random_device rnd;
	std::mt19937 mt32(rnd());
	std::uniform_int_distribution<int>engine(MIN, MAX);
	return engine(mt32);
}
/*--------Library Zone!--------*/

string s;
int next_[200005][26];
int dp[200005],fuku[200005],ans[200005];
signed main() {
	cin>>s;
	rep(i,s.size()){
		dp[i]=inf;
	}
	rep(i,26)next_[s.size()][i]=s.size();
	for(int i=s.size()-1;i>=0;i--){
		rep(j,26)next_[i][j]=next_[i+1][j];
		next_[i][s[i]-'a']=i;
	}
	dp[s.size()]=1;
	/*rep(i,s.size()){
		rep(j,26)cout<<next_[i][j]<<" ";
		cout<<endl;
	}*/
	for(int i=s.size()-1;i>=0;i--){
		rep(j,26){
			if(next_[i][j]==s.size()){
				if(dp[i]>1){
					dp[i]=1;
					fuku[i]=s.size();
					ans[i]=j;
				}
			}
			else if(dp[i]>dp[next_[i][j]+1]+1){
				dp[i]=dp[next_[i][j]+1]+1;
				fuku[i]=next_[i][j]+1;
				ans[i]=j;
			}
		}
	}
	//rep(i,s.size())cout<<(char)(ans[i]+'a');
	string res;
	int now=0;
	while(now<s.size()){
		res.push_back((char)('a'+ans[now]));
		now=fuku[now];
		//cout<<now<<endl;
	}
	cout<<res<<endl;
}
