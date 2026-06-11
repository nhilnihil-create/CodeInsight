#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    ll x;
    cin >> x;

    if(x%11 == 0) cout << (x/11)*2 << endl;
    else if(x%11 <= 6 ) cout << (x/11)*2 + 1 << endl;
    else if(x%11 > 6) cout << (x/11)*2 + 2 << endl;

    return 0;
}