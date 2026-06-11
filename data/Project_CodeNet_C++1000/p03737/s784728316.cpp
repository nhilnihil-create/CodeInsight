#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    string a, b, c;
    cin >> a >> b >> c;
    
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    transform(b.begin(), b.end(), b.begin(),::toupper);
    transform(c.begin(), c.end(), c.begin(),::toupper);
    cout << a[0] << b[0] << c[0] << endl;

    return 0;
}