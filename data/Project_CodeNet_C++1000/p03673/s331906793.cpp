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
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    if (n % 2 == 0) {
        for (int i = n - 1; i >= 1; i = i - 2) {
            cout << A[i] << " ";
        }
        for (int i = 0; i < n; i = i + 2) {
            cout << A[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = n - 1; i >= 0; i = i - 2) {
            cout << A[i] << " ";
        }
        for (int i = 1; i < n; i = i + 2) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}