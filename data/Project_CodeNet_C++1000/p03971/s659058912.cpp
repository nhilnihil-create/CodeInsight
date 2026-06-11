#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, A, B;
    string S;
    cin >> N >> A >> B;
    cin >> S;

    int cnt1 = 0;
    int cnt2 = 0;
    
    rep(i, N) {
        string ans = "Yes";
        if (S[i] == 'c') ans = "No";
        if (S[i] == 'a') {
            if (cnt1 < A+B) {
                cnt1++;
            } else { ans = "No"; }
        }
        if (S[i] == 'b') {
            if (cnt1 < A+B && cnt2 < B) {
                cnt1++; cnt2++;
            } else { ans = "No"; }
        }
        cout << ans << endl;

    }

    return 0;

}