#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;
const int mod = 1e9+7;

void comb(vvll &v) {
    rep(i,v.size()) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int k = 1; k < v.size(); k++) {
        for (int j = 1; j < k; j++) {
            v[k][j] = v[k-1][j-1] + v[k-1][j];
        }
    }
}

int main() {
    int N, a, b; cin >> N >> a >> b;
    int A = a;
    map<ll,int,greater<ll>> mp;
    rep(i,N) {
        ll v; cin >> v;
        mp[v]++;
    }
    vvll v(51,vll(51,0));
    comb(v);
    ll choose = 0;
    ll sum = 0;
    double mean;
    P p_begin = *mp.begin();
    if (a <= p_begin.second) {
        for (int i = a; i <= min(p_begin.second,b); i++) {
            choose += v[p_begin.second][i];
        }
        mean = p_begin.first;
    } else {
        for (P p : mp) {
            ll value = p.first;
            int ct = p.second;
            if (a > ct) {
                a -= ct; 
                sum += value * ct;
             } else {
                sum += a * value;
                choose += v[ct][a];
                mean = (double)sum / A;
                break;
            }
        }
    }
    printf("%.10f\n%lld\n",mean,choose);

}