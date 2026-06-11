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
#define sz(v) (ll)(v).size()
#define inf 1e18
#define md 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define tel(a){cout<<a<<"\n";}
#define tell(a,b){cout<<a<<" | "<<b<<"\n";}
#define telll(a,b,c){cout<<a<<" | "<<b<<" | "<<c<<"\n";}
#define teln(v,n){cout<<"v- ";rep(o,0,n)cout<<v[o]<<" ";cout<<"\n";}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

// k=a1+a2+...an>nan+1
int main(){
    IOS;
 	
 	ll C[51][51];
 	rep(i,0,51)C[0][i]=0,C[i][0]=1;
 	rep(i,1,51)rep(j,1,51)C[i][j]=C[i-1][j]+C[i-1][j-1];
 	ll n;cin>>n;
 	ll a,b;cin>>a>>b;
 	vll v;
 	map<ll,ll>mp;
 	rep(i,0,n){ll x;cin>>x;v.pb(x);mp[x]++;}
 	sort(all(v)); reverse(all(v));
 	ll sum=0,cnt=a,way=0,j=a,mn=v[a-1],c=0;
 	rep(i,0,a){
 		sum+=v[i];
 		if(mn==v[i])c++;
 	}
 	ld x=sum/(ld)cnt;
 	if(c==a){
 		rep(i,a,mp[mn]+1)if(i<=b)way+=C[mp[mn]][i];
 	}
 	else way=C[mp[mn]][c];
 	cout<<setprecision(10)<<x<<"\n"<<way;
     
     
     
     
     return 0;
}
