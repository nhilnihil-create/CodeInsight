#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
    }
    
    vector<ll> hist(1e5+1, 0);
    for (int i = 0; i < N; i++)
    {
        hist[a[i]] += b[i];
    }

    ll count = 0;
    int ans = 0;
    for (int n = 1; n <= 1e5; n++)
    {
        count += hist[n];
        if(count >= K) {
            ans = n;
            break;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
