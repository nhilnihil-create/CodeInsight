#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int A, B, C;


void input() {
    cin >> A >> B >> C;
}


ll gcd(ll a, ll b) {
    while (b) {
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}


int main() {
    input();
    string ans;
    ll g = gcd(A, B);
    if (C % g == 0) ans = "YES";
    else ans = "NO";
    cout << ans << endl;
}
