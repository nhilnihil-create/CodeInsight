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
int a[N];
ll dp[55][3000];
int n,k;
int main(){
	cin>>n>>k;
	dp[0][0]=1;
	f(i,1,n){
		int x;cin>>x;
		F(j,i,1){
			f(l,x,k*n){
				dp[j][l]+=dp[j-1][l-x];	
			}
		}
	}
	ll ans=0;
	f(i,1,n) ans+=dp[i][i*k];
	cout<<ans;
}