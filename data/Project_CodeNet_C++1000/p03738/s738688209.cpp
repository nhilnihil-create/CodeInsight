#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    string a, b; cin >> a >> b;
    if (a.size() > b.size()) {
        cout << "GREATER" << endl;
    } else if (a.size() < b.size()) {
        cout << "LESS" << endl;
    } else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > b[i]) {
                cout << "GREATER" << endl;
                return 0;
            } else if (a[i] < b[i]) {
                cout << "LESS" << endl;
                return 0;
            }
        }

        cout << "EQUAL" << endl;
    }
    return 0;
}