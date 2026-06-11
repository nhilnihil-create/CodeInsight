#include <bits/stdc++.h>
using namespace std;

int main()  {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int &it : a) cin >> it;
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 1; i < 2 * n; i += 2) {
        sum += min(a[i - 1], a[i]);
    }
    cout << sum;
    return 0;
}
