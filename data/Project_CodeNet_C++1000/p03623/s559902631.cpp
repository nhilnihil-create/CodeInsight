#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    int x, a, b;
    cin >> x >> a >> b;

    if(abs(x-a) < abs(x-b)) cout << 'A' << endl;
    else cout << 'B' << endl;

    return 0;
}