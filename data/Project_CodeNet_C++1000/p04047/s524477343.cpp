#include <bits/stdc++.h>
using namespace std;

int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int &it : a) cin >> it;
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        sum += a[i];
    }
    cout << sum;
    return 0;
}
