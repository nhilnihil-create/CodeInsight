#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,p[1000005],M[1000005],beg,sum;
ll ans=1;
int x[1000005];
int main(){
	cin>>n;
	rep(i,n) cin>>p[i];
	rep(i,n){
		int a = p[i]-i*2;
		if(a>=1) beg++,sum++;
		else break;
	}
	rep(i,n){
		ans = ans*1LL*(beg==n?sum:(1+sum))%mod;
		while(beg<n && p[beg]-(beg-i-1)*2 >=1){
			beg++; sum++;
		}
		sum--;
	}
	cout<<ans<<endl;
}