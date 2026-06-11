#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    int a, b;
    cin >> a >> b;
    if(a+b < 24) cout << a + b << endl;
    else cout << a + b - 24 << endl;

    return 0;
}