#include<bits/stdc++.h>
using namespace std;
int arr[100010];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    long long answer = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] + arr[i + 1] > x) {
            int d = arr[i] + arr[i + 1] - x;
            answer += d;
            if (d > arr[i + 1]) {
                arr[i + 1] = 0;
                d -= arr[i + 1];
                arr[i] -= d;
            } else {
                arr[i + 1] -= d;
            }
        }
    }
    cout << answer;
}