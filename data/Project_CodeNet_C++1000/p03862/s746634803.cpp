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
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const double pi=acos(-1.0);//NOTE:PI
const double eps=1e-5;
const int INF=1e9,mod=1e9+7,N=1e6+1;
int a[N];
ll ans=0;
int n,x;
int main(){
	cin>>n>>x;
	f(i,1,n) cin>>a[i];
	if(a[1]>x){
		ans+=a[1]-x;
		a[1]=x;
	}
	f(i,2,n){
		if(a[i]+a[i-1]>x){
			ll tmp=a[i]+a[i-1]-x;
			ans+=tmp;
			a[i]-=tmp;
		}
	}
	cout<<ans;
}	
	
	
	
