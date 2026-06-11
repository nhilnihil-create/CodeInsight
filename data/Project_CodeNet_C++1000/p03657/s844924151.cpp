#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    int a, b;
    bool ok = false;
    cin >> a >> b;
    if(a%3 == 0) ok = true;
    if(b%3 == 0) ok = true;
    if((a+b)%3 == 0) ok = true;

    if(ok) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}