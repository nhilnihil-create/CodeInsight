#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define mod 1000000007
using ll=long long;
const int INF=1000000000;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}
 
struct IOSetup{
    IOSetup(){
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout<<fixed<<setprecision(12);
    }
} iosetup;
 
template<typename T1,typename T2>
ostream &operator<<(ostream &os,const pair<T1,T2>&p){
    os<<p.first<<" "<<p.second;
    return os;
}
 
template<typename T>
ostream &operator<<(ostream &os,const vector<T>&v){
    for(int i=0;i<(int)v.size();i++) os<<v[i]<<(i+1==(int)v.size()?"":" ");
    return os;
}

template<typename T1,typename T2>
istream &operator>>(istream &is,pair<T1,T2>&p){
    is>>p.first>>p.second;
    return is;
}

template<typename T>
istream &operator>>(istream &is,vector<T>&v){
    for(T &x:v)is>>x;
    return is;
}


signed main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> g(n);
    rep(i,m){
        int u,v;cin>>u>>v;u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cntsolo=0;
    vector<int> bi,notbi;

    vector<int> check(n,-1);
    bool bipf=true;
    int cnt=0;

    function<void(int)> dfs=[&](int now){
        cnt++;
        for(auto to:g[now]){
            if(check[to]==-1){
                check[to]=(check[now]^1);
                dfs(to);
            }else{
                if(check[now]==check[to]) bipf=false;
            }
        }
    };

    rep(i,n)if(check[i]==-1){
        if(g[i].size()==0){
            cntsolo++;
            continue;
        }

        bipf=true;
        cnt=0;
        check[i]=0;
        dfs(i);
        if(bipf)    bi.push_back(cnt);
        else        notbi.push_back(cnt);
    }

    
    ll res=0;
    res+=(ll)cntsolo*cntsolo;
    res+=(ll)2*cntsolo*(n-cntsolo);

    ll cbi=(ll)bi.size();
    ll cnb=(ll)notbi.size();

    res+=2*cbi*cbi;
    res+=cnb*cnb;

    res+=2*cbi*cnb;

    cout<<res<<endl;
    return 0;
}
