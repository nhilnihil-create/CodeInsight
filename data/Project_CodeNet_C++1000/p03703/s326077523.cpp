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

#define ll   long long 
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define S second
#define F first
#define die() return 0;
 
#define md          1000000007
#define fmd         998244353 
#define M           1000011
#define N            18
ll exp(ll a,ll b){if(b<0)return 0;ll r=1;while(b){if(b&1)r=r*a%md,r%=md;a=a*a%md;b/=2;}return r;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
class BIT{
public:
    int n;
    vector<int> B;
    BIT(int sz){
        n=sz;
        B=vector<int> (n+1);
    }
    void up(int x,int y=1){
        for(;x<=n;x+=x&-x)B[x]+=y;
    }
    int sum(int x){int s=0;
        for(;x>=1;x-=x&-x)s+=B[x];
        return s;
    }

};
int bc;

int solve(){
    ll n,i,j,k,m,x,y,z;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(i=1;i<=n;++i)cin>>a[i],a[i]+=a[i-1];
	map<ll,ll> mp;
	for(i=0;i<=n;++i)mp[a[i]-k*i];
	for(auto x:mp)mp[x.F]=++bc;
	BIT b(bc);
	ll ans=0;
	b.up(mp[0]);
	for(i=1;i<=n;++i){
		ll bef=a[i]-k*i;
		ans+=(b.sum(mp[bef]));
		b.up(mp[bef]);
	}
	cout<<ans<<"\n";

	die();
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