#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    int x, t;
    cin >> x >> t;
    if(x < t) cout << 0 << endl;
    else cout << x - t << endl;
    
    return 0;
}