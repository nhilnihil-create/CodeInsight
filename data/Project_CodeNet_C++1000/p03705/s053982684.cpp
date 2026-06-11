#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    ll n, a, b;
    cin >> n >> a >> b;

    if(a > b) cout << 0 << endl;
    else if(n == 1){
        if(b - a > 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
    else{
        cout << (b - a) * (n - 2) + 1 << endl;
    }

    return 0;
}