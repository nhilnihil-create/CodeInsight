#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mk make_pair
#define fi first
#define se second
#define vll vector<ll>
#define pii pair<ll,ll>
#define vvll vector< vector<ll> >
#define pb push_back
#define sz(v) (v).size()
#define inf 1e18
#define md 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define tel(a){cout<<a<<"\n";}
#define tell(a,b){cout<<a<<" | "<<b<<"\n";}
#define telll(a,b,c){cout<<a<<" | "<<b<<" | "<<c<<"\n";}
#define teln(v,n){cout<<"v- ";rep(o,0,n)cout<<v[o]<<" ";cout<<"\n";}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tihs if(fopen("inp.txt","r"))freopen("inp.txt", "r", stdin),freopen("out.txt", "w", stdout);
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
 
#define M 100010

int main(){
	IOS;
	tihs;

	ll n;cin>>n;n*=2;
	ll a[n];
	rep(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll ans=0,i=0;
	while(i<n)ans+=a[i],i+=2;
	tel(ans);
	

	return 0;
}