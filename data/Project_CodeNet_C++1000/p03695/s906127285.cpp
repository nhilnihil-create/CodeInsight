#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

int main() {
    int n; cin >> n;
    set<int> s;
    int cnt = 0;
    rep(i, n) {
        int a; cin >> a;
        int add;
        if(a < 400) add = 1;
        else if(a < 800) add = 2;
        else if(a < 1200) add = 3;
        else if(a < 1600) add = 4;
        else if(a < 2000) add = 5;
        else if(a < 2400) add = 6;
        else if(a < 2800) add = 7;
        else if(a < 3200) add = 8;
        else {
            cnt++;
            continue;
        }
        s.insert(add);
    }
    cout << max<int>(1, s.size()) << ' ' << s.size() + cnt << endl;
}