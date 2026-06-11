#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i < n; i++)
#define repv(i,n) for(int i = n-1; i >= 0; i--)
#define fi first
#define sc second
#define pb push_back
using namespace std;
typedef long long ll;

char BUF[3500000];
inline void I(int&a){scanf("%d",&a);}
inline void I(int&a,int&b){scanf("%d%d",&a,&b);}
inline void I(int&a,int&b,int&c){scanf("%d%d%d",&a,&b,&c);}
inline void I(int&a,int&b,int&c,int&d){scanf("%d%d%d%d",&a,&b,&c,&d);}
inline void L(ll&a){scanf("%lld",&a);}
inline void L(ll&a,ll&b){scanf("%lld%lld",&a,&b);}
inline void L(ll&a,ll&b,ll&c){scanf("%lld%lld%lld",&a,&b,&c);}
inline void L(ll&a,ll&b,ll&c,ll&d){scanf("%lld%lld%lld%lld",&a,&b,&c,&d);}
inline void S(string&str){str.clear();scanf("%s",BUF);int s=strlen(BUF);rep(i,s)str.pb(BUF[i]);}
inline void SV(vector<int>&v){v.clear();scanf("%s",BUF);int s=strlen(BUF);rep(i,s)if('a'<=BUF[i]&&BUF[i]<='z')v.pb(BUF[i]-'a');else v.pb(BUF[i]-'A');}

const auto EPS = 1e-10;
const auto INF = 100000000;
const auto MOD = 1000000007;
typedef pair<ll,ll> P;

int n, m;
bool saw[100000];
bool ssaw[100000];
int dep[100000];
vector<int> e[100000];

void init(int v, int d){
    ssaw[v] = true;
    rep(i,e[v].size()){
        if(ssaw[e[v][i]]) continue;
        dep[e[v][i]] = d+1;
        init(e[v][i], d+1);
    }
}

bool check(int v){
    saw[v] = true;
    rep(i,e[v].size()){
        if(!saw[e[v][i]]){
            bool rec = check(e[v][i]);
            if(!rec) return false;
        } else{
            if(abs(dep[v]-dep[e[v][i]])%2 == 0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    memset(saw,0,sizeof(saw));
    I(n,m);
    rep(i,m){
        int u, v;
        I(u,v); u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ll counter = 0;
    ll count = 0;
    ll ans = 0;
    ll hoge = 0;
    rep(i,n){
        if(ssaw[i] == false){
            if(e[i].size() == 0){
                ans += (n-hoge)*2-1;
                hoge++;
                continue;
            }
            dep[i] = 0;
            init(i,0);
            if(!check(i)){
                count++;
            }
            counter++;
        }
    }
    ans += count*counter;
    ans += (counter-count)*(count+(counter-count)*2);
    cout << ans << endl;
}






























