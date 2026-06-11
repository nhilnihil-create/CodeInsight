#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<int> num(N);

    rep(i, N) {
        cin >> num[i];
    }

    int ans = 1001001001;

    for(int i = -100; i < 101; i++) {
        int sum = 0;
        rep(j, N) {
            sum += (num[j] - i) * (num[j] - i);
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;
}