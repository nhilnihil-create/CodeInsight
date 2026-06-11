#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    double dense = -1;
    int answ = 0, anss = 0;
    for (int an = 0; 100*a*an <= f; ++an) {
        for (int bn = 0; 100*a*an + 100*b*bn <= f; ++bn) {
            int totw = 100*a*an + 100*b*bn;
            for (int cn = 0; totw + c*cn <= f; ++cn) {
                for (int dn = 0; totw + c*cn + d*dn <= f; ++dn) {
                    int tots = c*cn + d*dn;
                    int maxs = (e*totw) / 100;
                    if (tots > maxs) continue;
                    if (chmax(dense, (double)(100*tots)/(totw+tots))) {
                        answ = totw + tots;
                        anss = tots;
                    }
                }
            } 
        }
    }
    cout << answ << " " << anss << endl;
}