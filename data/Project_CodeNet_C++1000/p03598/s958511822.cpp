#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        a = x[i] * 2;
        b = (k - x[i]) * 2;
        ans += min(a, b);
    }
    cout << ans << endl;
    
    return 0;
}