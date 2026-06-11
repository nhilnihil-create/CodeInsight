#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    int ans = 1;
    int cnt = 0;
    for(int i = N-1; i > 0; i--) {
        if(A[i] == A[i-1]) {
            ans*=A[i];
            i--;
            cnt++;
        }
        if(cnt == 2) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}
