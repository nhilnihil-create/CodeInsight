#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;
    priority_queue<int> y;
    priority_queue<int, vector<int>, greater<int>> x;
    vector<ll> sumx(n + 1), sumy(n + 1), a(3 * n);

    for(int i = 0; i < 3 * n; i++) {
        cin >> a[i];
        if(i < n     ) sumx[0] += a[i], x.push(a[i]);
        if(2 * n <= i) sumy[0] += a[i], y.push(a[i]);
    }

    for(int i = 0; i < n; i++) {
        x.push(a[i + n]);
        sumx[i + 1] = sumx[i] + a[i + n] - x.top(); //sumx[i] := 前からn + i個見た時に大きいやつをN個取った
        x.pop();
        y.push(a[2 * n - i - 1]);
        sumy[i + 1] = sumy[i] + a[2  * n - i - 1] - y.top(); //sum[i] := 後からi + n個見た時に小さいやつをN個取った
        y.pop();
    }

    ll ans = -1e18;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, sumx[i] - sumy[n - i]);
    }
    cout << ans << endl;
}