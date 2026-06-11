#include"bits/stdc++.h"
#define int long long
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define itr(i,x) for(auto i=(x).begin();i!=(x).end();++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
typedef pair<int,int> P;
const int mod=1000000007;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);}

signed main(){
	int n;cin>>n;
	vector<string> s(2);
	rep(i,2) cin>>s[i];
	deque<int> vertical;
	rep(i,n) if(s[0][i]==s[1][i]) vertical.push_back(i);
	vertical.push_back(n);
	vector<int> dp(n+1);
	dp[0]=1;
	bool flag = false;
	rep(i,n){
		if(i==vertical.front()){
			if(i==0) dp[i+1]=3;
			else if(flag) dp[i+1]=dp[i]*2%mod;
			else dp[i+1]=dp[i];
			vertical.pop_front();
			flag=true;
		}
		else{
			if(i==0) dp[i+2]=6;
			else if(flag)dp[i+2]=dp[i]*2%mod;
			else dp[i+2]=dp[i]*3%mod;
			flag=false;
			i++;
		}
	}
	cout<<dp[n]<<endl;
}
