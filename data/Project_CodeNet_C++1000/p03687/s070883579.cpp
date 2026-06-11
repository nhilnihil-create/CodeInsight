#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    string str;
    cin >> str;
    int n = str.length();
    vector<vector<int> > alphabet(27);
    rep(i, n) {
        alphabet[(char)str[i] - 'a'].push_back(i);
    }
    int ans = 10000;
    rep(i, 26) {
        if(alphabet[i].size() == 0) continue;
        else {
            //　二分探索法
            int lb = -1, ub = 101;
            while(ub - lb > 1) {
                int mid = (lb + ub) / 2;
                bool ok = true;
                rep(j, alphabet[i].size()) {
                    if(j == 0) {
                        if(alphabet[i][j] - 0 > mid) {
                            ok = false;
                        }
                    }
                    if(alphabet[i].size() - 1 - j > 0) {
                        if(alphabet[i][j+1] - alphabet[i][j] - 1 > mid) {
                            ok = false;
                        }
                    }
                    if(j == alphabet[i].size()-1) {
                        if(n - 1 - alphabet[i][j] > mid) {
                            ok = false;
                        }
                    }
                    if(!ok) {
                        break;
                    }
                }
                if(ok) {
                    ub = mid;
                }
                else {
                    lb = mid;
                }
            }
            chmin(ans, ub);
        }
    }
    cout << ans << endl;
}