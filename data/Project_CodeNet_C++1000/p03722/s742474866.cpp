//小数点以下　cout << fixed << setprecision(10) << num << endl;
//桁数はlog10(mid)でやれ　log(mid)/log(10)はWA
//long*long<0で判定するな
//開区間と閉区間
//アルファベットが何番目かは x=s[i]-'a'
//bfsはmain()内で　rep(i,h)rep(j,w)rep(i,4)でバグ
//切り上げ：(a+(b-1))/b
//32bit以上は 1ull<<j
// map 初期値0 for(auto itr=mp.begin();itr!=mp.end();++itr) itr->fi itr->se で全探索
// for(auto u:mp) u.fi u.se も可能
//n個のgcd,lcmは一つずつみて更新していく
//大きな数を扱うときは素因数分解した形で持っておく
// (l/a[i]) = l*powmod(a[i],MOD-2)%MOD;
//auto itr=lower_bound(ALL(a),key) a[itr-a.begin()]
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

struct edge{
    int from;
    int to;
    ll cost;
};

signed main(){
    int n,m;
    cin >> n >> m;
    vector<edge> v;
    ll d[n];
    rep(i,n) d[i] = 1001001001001001;
    d[0]=0;
    rep(i,m){
        edge e;
        cin >> e.from >> e.to >> e.cost;
        e.from--; e.to--;
        e.cost*=-1;
        v.pb(e);
    }
    //for(auto e:v) cout << e.from <<" "<<e.to<<" "<<e.cost<<endl;
    bool ng=0;
    rep(i,n){
        rep(j,v.size()){
            edge e = v[j];
            if(d[e.to] > d[e.from]+e.cost){
                d[e.to] = d[e.from] + e.cost;
                if(i==n-1){
                    ng=1;
                    break;
                }
            }
        }
    }
    if(ng){
        ll pre=d[n-1];
        rep(i,n){
            rep(j,v.size()){
                edge e = v[j];
                if(d[e.to] > d[e.from]+e.cost){
                    d[e.to] = d[e.from] + e.cost;
                    if(i==n-1){
                        ng=1;
                        break;
                    }
                }
            }
        }
        if(pre!=d[n-1]){
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << -1*d[n-1] << endl;
}
