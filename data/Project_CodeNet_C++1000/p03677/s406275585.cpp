#include<bits/stdc++.h>
using namespace std;
 
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
#define ll long long  
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define S second
#define F first
#define die() return 0;
 
 
#define md          1000000007
#define fmd         998244353 
#define M           100011
#define N            18
ll exp(ll a,ll b){if(b<0)return 0;ll r=1;while(b){if(b&1)r=r*a%md,r%=md;a=a*a%md;b/=2;}return r;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}

class BIT{
	public:
		int n;
		vector<ll> B;
		BIT(int sz){
			n=sz;
			B=vector<ll>(n+1);
		}
		void up(int x,int val=1){
			for(;x<=n;x+=x&-x)B[x]+=val;
		}
		ll get(int x){
			ll s=0;
			for(;x>=1;x-=x&-x)s+=B[x];
			return s;
		}

};
void addRange(BIT &b,int l,int r,ll val){
	if(l>r)
		return ;
	b.up(l,val);
	b.up(r+1,-val);
}
int solve(){
    ll n,i,j,k,m,x,y,z;
    cin>>n>>m;
    vector<int> a(n);
    for(i=0;i<n;++i)cin>>a[i];

    BIT b(m+11),mi(m+11);

	for(i=0;i+1<n;++i){
		if(a[i+1]>=a[i]){
			addRange(b,1,a[i],a[i+1]-a[i]);
			addRange(b,a[i+1]+1,m,a[i+1]-a[i]);

			addRange(b,a[i]+1,a[i+1],1+a[i+1]);
			addRange(mi,a[i]+1,a[i+1],-1);
		}
		else{
			ll def=(m-a[i])+(a[i+1]);
			addRange(b,a[i+1]+1,a[i],def);

			addRange(b,a[i]+1,m,a[i+1]+m+1);
			addRange(mi,a[i]+1,m,-1);

			addRange(b,1,a[i+1],a[i+1]+1);
			addRange(mi,1,a[i+1],-1);


		}
	}
	ll ans=1e17;
	for(i=1;i<=m;++i){
		ans=min(ans,b.get(i)+i*mi.get(i));
	}cout<<ans<<"\n";






	die();
 
}
void prec(){

} 
 
int main(){
 
 
#ifndef ONLINE_JUDGE
    double _tBeg=clock();
#endif
 
     
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
    int t;
    t=1;;
    // prec();
    // cin>>t;
 
    while(t--){
 
        solve();
    }
 
 
 
 
 
 
#ifndef ONLINE_JUDGE
    double _tEnd=clock();
    // printf("\ntotal time %.6f\n",(_tEnd-_tBeg)/CLOCKS_PER_SEC);
#endif
 
    die();
}