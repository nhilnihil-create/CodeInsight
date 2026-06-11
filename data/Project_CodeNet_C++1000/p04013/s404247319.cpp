#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int(i)=int (a);i<=int (b);i++)
#define ff(i,a,b) for(int(i)=int (a);i<int (b);i++)
#define F(i,a,b) for(int(i)=int (a);i>=int (b);i--)
#define foreach(i,x) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define vt vector
#define ll long long
#define lower(p,x) lower_bound(all(p),x)
#define upper(p,x) upper_bound(all(p),x)
#define ms(a,x) memset(a,x,sizeof a)
#define minn(a,b,c,d) min(a,min(b,min(c,d))) 
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const double pi=acos(-1.0);//NOTE:PI
const double eps=1e-5;
const int INF=1e9,mod=1e9+7,N=1e6+6;
ll a[N];
ll dp[55][55][2500];
ll n,k;
ll back(ll pos,ll take,ll sum){
	if(pos==n) {
		if(static_cast<double>(sum)/static_cast<double>(take)==k) return 1;
		return 0;	
	}
	if(dp[pos][take][sum]!=-1) return dp[pos][take][sum];
	return dp[pos][take][sum]=back(pos+1,take+1,sum+a[pos])+back(pos+1,take,sum);

}
int main(){
	cin>>n>>k;ms(dp,-1);
	ff(i,0,n) cin>>a[i];
	cout<<back(0,0,0);
}
