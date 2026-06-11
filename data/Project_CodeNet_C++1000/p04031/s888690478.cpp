#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void) {
    io;
    int N; cin >> N;
    vector<int> input(N);
    long long ans = INT_MAX;

    for (int i = 0; i < N; i++) cin >> input[i];
    for (int i = -100; i <= 100; i++) {
        long long sum(0);
        for (int k = 0; k < N; k++) {
            sum += (input[k]-i) * (input[k]-i);
        }
        ans = min(sum, ans);
    }
    cout << ans << "\n";
    return 0;
}

