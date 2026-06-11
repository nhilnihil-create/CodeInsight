#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int gcd(int a, int b) {
    if(a % b == 0) return b;
    else return(gcd(b, a % b));
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(gcd(a, b) == 1) {
        cout << "YES" << endl;
    } 
    else {
        if(c % gcd(a, b) == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
