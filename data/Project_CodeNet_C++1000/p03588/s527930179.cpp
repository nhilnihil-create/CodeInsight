#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
 
typedef long long ll;

int main() {
    int N, A, B, maxA = 0, ans = 0;
    cin >> N;
    rep(i, N) {
        cin >> A >> B;
        if (A > maxA) {
            maxA = A;
            ans = A + B;
        }
    }
    cout << ans << endl;
}