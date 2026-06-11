#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    int curr_min = INT_MAX;

    for (int i = -100; i <= 100; i++) {
        int curr = 0;
        for (int j = 0; j < n; j++) {
            curr += (arr[j] - i) * (arr[j] - i);
        }

        if (curr < curr_min) {
            curr_min = curr;
            ans = curr;
        }
    }

    cout << ans << endl;

    return 0;
}