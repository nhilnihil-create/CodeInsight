#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n);i>=0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
ll const mod = 998244353;
const ll MAX = 300000;
using vi = vector<int>;
using vc = vector<char>;
using vd = vector<double>;
using vs = vector<string>;
using vp = vector<P>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvc = vector<vector<char>>;
using vvp = vector<vector<P>>;
using vvb = vector<vector<bool>>;
template <typename T>
bool chmax(T& a, const T b) { if (a < b) { a = b; return true; } return false; }
template <typename T>
bool chmin(T& a, const T b) { if (a > b) { a = b; return true; } return false; }


//////////////////////////////////////


int main() {
    string s;
    cin >> s;
    int n = s.size();
    for(int i=n;i>=0;) {
        bool ok = false;
        int index = i;
        if (i - 5 < 0)break;
        if (s.substr(i - 5, 5) == "dream") {
            index = i - 5;
            if (index == 0) {
                cout << "YES" << endl;
                return 0;
            }
            ok = true;
        }

        if (s.substr(i - 5, 5) == "erase") {
            index = i - 5;
            if (index == 0) {
                cout << "YES" << endl;
                return 0;
            }
            ok = true;
        }
        if (index!=0&&i - 6 < 0)break;
        if (s.substr(i - 6, 6) == "eraser") {
            index = i - 6;
            if (index == 0) {
                cout << "YES" << endl;
                return 0;
            }
            ok = true;
        }
        if (index>0&&i - 7 < 0)break;
        if (s.substr(i - 7, 7) == "dreamer") {
            index = i - 7;
            if (index == 0) {
                cout << "YES" << endl;
                return 0;
            }
            ok = true;
        }

        i = index;
        if (!ok) {
            break;
        }
        else if (i == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}