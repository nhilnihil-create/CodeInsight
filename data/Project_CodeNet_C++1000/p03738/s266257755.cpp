#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
string A, B;


void input() {
    cin >> A >> B;
}


int main() {
    input();
    int an = A.size();
    int bn = B.size();
    string ans;
    if (an != bn) {
        if (an > bn) ans = "GREATER";
        else ans = "LESS";
        cout << ans << endl;
        return 0;
    }
    rep(i, an) {
        if (A[i] != B[i]) {
            if (A[i] > B[i]) ans = "GREATER";
            else ans = "LESS";
            cout << ans << endl;
            return 0;
        }
    }
    ans = "EQUAL";
    cout << ans << endl;
}
