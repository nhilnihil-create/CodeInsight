#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<ll> a(3 * N);
    for (int i = 0; i < 3 * N; i++)
    {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end(), greater<int>());
    ll ans = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        if (i % 2 == 1)
        {
            ans += a[i];
        }
        
    }
    cout << ans << endl;
  return 0;
}