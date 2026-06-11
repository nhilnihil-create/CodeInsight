#include <bits/stdc++.h>


using namespace std;
using ll= long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;

int main (){
    ll n, m, ans;
    cin >> n >> m;
    if (m < 2*n){
        ans = m/2;
    }
    else {
        ans = n;
        m -= 2*n;
        ans+=m/4;
    }
    cout << ans << endl;
    return 0;
}