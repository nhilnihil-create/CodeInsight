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


int main() {
    input();
    string ans;
    if (A <= C && C <= B) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
}
