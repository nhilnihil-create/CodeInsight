#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    string a, b, c;
    cin >> a >> b >> c;

    char next = a[0];
    int cnt_a = 1, cnt_b = 0, cnt_c = 0;

    while (true) {
        if (next == 'a') {
            if (cnt_a == a.length()) {
                cout << "A" << endl;
                break;
            } else {
                next = a[cnt_a];
                cnt_a++;
            }
        }
        if (next == 'b') {
            if (cnt_b == b.length()) {
                cout << "B" << endl;
                break;
            } else {
                next = b[cnt_b];
                cnt_b++;
            }
        }
        if (next == 'c') {
            if (cnt_c == c.length()) {
                cout << "C" << endl;
                break;
            } else {
                next = c[cnt_c];
                cnt_c++;
            }
        }
    }
    
    return 0;
}