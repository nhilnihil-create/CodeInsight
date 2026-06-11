#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define speed() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 1000000000; // 10^9

int main() {
    int A, B, C; cin >> A >> B >> C;
    if (A == B && B == C && A % 2 == 0) cout << "-1" << endl;
    else {
        int cnt = 0, p, q, r;
        while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
            p = A; q = B; r = C;
            A = (q+r) / 2;
            B = (p+r) / 2;
            C = (p+q) / 2;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}