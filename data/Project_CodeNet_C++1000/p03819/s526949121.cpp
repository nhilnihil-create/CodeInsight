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

class BIT{
public:
    int n;
    vector<int>B;
    BIT(int sz){
        n=sz;
        B=vector<int> (n+1);
    }
    void up(int x,int y){
        for(;x<=n;x+=x&-x)B[x]+=y;
    }
    int sum(int x){int s=0;
        for(;x>=1;x-=x&-x)s+=B[x];
        return s;
    }

};


int solve(){
    ll n,i,j,k,m,x,y,z;
    cin>>n>>m;
    vector<pair<int,int> > v[m+1];
    BIT b(m);
    vector<int> ans(m+10);

    for(i=1;i<=n;++i){
        int l,r;
        cin>>l>>r;
        v[r-l+1].pb({l,r});
        ans[1]++;
        ans[r-l+2]--;
    }

    for(i=1;i<=m;++i){
        for(j=i;j<=m;j+=i){
            int cnt=b.sum(j);
            // trace(i,j,cnt);
            if(cnt){
                ans[i]+=cnt;
                ans[i+1]-=cnt;
            }
        }
        if(!v[i].size())continue;
        for(auto x:v[i]){
            b.up(x.F,1);
            b.up(x.S+1,-1);
        }
    }
        for(i=1;i<=m;++i)ans[i]+=ans[i-1];
        for(i=1;i<=m;++i)cout<<ans[i]<<"\n";




    

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