#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int (i)=int(a);i<=int (b);i++)
#define ff(i,a,b) for(int (i)=int(a);i<int (b);i++)
#define F(i,a,b) for(int (i)=int (a);i>=int (b);i--)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define vt vector
#define ll long long
#define all(x) x.begin(),x.end()
#define lower(p,x) lower_bound(all(p),x)
#define upper(p,x) upper_bound(all(p),x)
#define ms(a,x) memset(a,x,sizeof a)
typedef pair<int,int> ii;
const double pi=acos(-1.0);
const double eps=1e-5;
const int INF=1<<30,mod=1e9,N=1e6+6;
/*int power(int a,int b,int p){
	int ans=1%p;
	for(;b;b>>1){
		if(b&1)  ans=(ll)ans*a%p;
		else a=(ll)a*a%p;
	}
	return ans;
}*/int n;
int main(){
	cin>>n;
	ll a=1,b=1;
	ff(i,0,n){
			ll x,y;
			cin>>x>>y;if(a*y==b*x) continue;
			ll z=max((a+x-1)/x,(b+y-1)/y);
			a=z*x,b=z*y;
	}
	cout<<a+b;
}
