#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i, 0, n) cin >> x[i];
    int ans = 0;
    rep(i, 0, n){
        if(abs(x[i]) < abs(x[i] - k)) ans += abs(x[i]);
        else ans += abs(x[i] - k);
    }
    cout << ans*2 << endl;
    return 0;
}
