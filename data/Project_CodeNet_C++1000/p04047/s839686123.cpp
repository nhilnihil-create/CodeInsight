#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1000000007;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n + n);
    for(int i = 0; i < n + n; i++)cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += a[i * 2];
    }
    cout << ans << endl;
}