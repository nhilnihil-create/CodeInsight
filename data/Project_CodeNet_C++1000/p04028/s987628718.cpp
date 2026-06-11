#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll MOD=1e9+7;
const ll HF=5e8+4;

ll tim(ll a, ll b){
	return (a*b)%MOD;
}
ll adm(ll a, ll b){
	return (a+b)%MOD;
}

int main(){
	int N;
	cin>>N;
	string S;
	cin>>S;
	int M=sz(S);
	ll dp[5005][5005];
	rep(i,N+1)rep(j,i+1)dp[i][j]=0;
	dp[0][0]=1;
	rep(i,N)rep(j,i+1){
		dp[i+1][j+1]=adm(tim(dp[i][j],2), dp[i+1][j+1]);
		dp[i+1][max(j-1,0)]=adm(dp[i][j], dp[i+1][max(j-1,0)]);
	}
	ll ans=dp[N][M];
	rep(_,M)ans=tim(ans, HF);
	cout<<ans<<endl;
}
