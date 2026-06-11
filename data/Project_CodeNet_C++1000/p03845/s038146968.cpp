#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        cout << sum - arr[a - 1] + b << endl;
    }
}