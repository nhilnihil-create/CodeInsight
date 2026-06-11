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
    int n = a.size() + b.size();
    int j = 0; int k = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << a[j];
            j++;
        } else {
            cout << b[k];
            k++;
        }
    }
    cout << endl;
    return 0;
}