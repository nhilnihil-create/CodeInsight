#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a * b <= c * d) cout << c * d << endl;
    else cout << a * b << endl;

    return 0;
}