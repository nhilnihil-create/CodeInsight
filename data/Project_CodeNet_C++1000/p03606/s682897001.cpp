#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;
    int l,r,ans=0;

    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        ans += r-l+1;
    }
    cout << ans << endl;
    return 0;
}