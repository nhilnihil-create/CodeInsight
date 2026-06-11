#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
string A, B, C;


void input() {
    cin >> A >> B >> C;
}


int main() {
    input();
    string ans;
    if (A.back() == B[0] && B.back() == C[0]) ans = "YES";
    else ans = "NO";
    cout << ans << endl;
}
