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
#define M           100011
#define N            18
ll exp(ll a,ll b){if(b<0)return 0;ll r=1;while(b){if(b&1)r=r*a%md,r%=md;a=a*a%md;b/=2;}return r;}

int solve(){
    ll n,i,j,k,m,x,y,z;
    string s1,s2;
    cin>>s1>>s2;
    n=s1.size();m=s2.size();
    vector<int> a(n+1),b(m+1);
    for(i=1;i<=n;++i){
    	if(s1[i-1]=='A')a[i]=a[i-1]+1;
    	else a[i]=a[i-1]+2;
    }
    for(i=1;i<=m;++i){
    	if(s2[i-1]=='A')b[i]=b[i-1]+1;
    	else b[i]=b[i-1]+2;
    }
    int q;
    cin>>q;
    while(q--){
    	int ai,bi,ci,di;
    	cin>>ai>>bi>>ci>>di;
    	x=a[bi]-a[ai-1];
    	y=b[di]-b[ci-1];
    	if(x%3!=y%3)cout<<"NO\n";
    	else cout<<"YES\n";
    }
    





    

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