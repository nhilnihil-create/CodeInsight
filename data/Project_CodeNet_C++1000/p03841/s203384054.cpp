#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <complex>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,-1,0,1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
    if(a>b){
        a = b; return true;
    }
    else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
    if(a<b){
        a = b; return true;
    }
    else return false;
}
template<typename T> inline void print(T &a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
    cout << a << " " << b << " " << c << "\n";
}
const ll mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
    ll n; cin >> n;
    vpl a(n);
    vl b(n);
    ll N = n * n;
    vl ans(N);
    set<ll> se;
    rep(i,N) se.insert(i);
    rep(i,n){
        cin >> a[i].first; a[i].first--;
        a[i].second = i;
        ans[a[i].first] = i+1;
        se.erase(a[i].first);
        b[i] = a[i].first;
    }
    sort(all(a));
    vl rest;
    rep(i,n){
        rep(j,a[i].second){
            auto itr = se.begin();
            if(*itr > a[i].first){
                puts("No");
                return 0;
            }
            ans[*itr] = a[i].second + 1;
            se.erase(itr);
        }
        rep(j,n-1-a[i].second){
            rest.push_back(a[i].second+1);
        }
    }
    for(auto i : rest){
        auto itr = se.upper_bound(b[i-1]);
        if(itr == se.end()){
            puts("No");
            return 0;
        }
        ans[*itr] = i;
        se.erase(itr);
    }
    puts("Yes");
    print(ans);
}