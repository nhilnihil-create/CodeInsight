#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    ll x, a, b;
    cin >> x >> a >> b;
    if ( a >= b )           cout << "delicious" << endl;
    else if (  b - a <= x ) cout << "safe" << endl;
    else                    cout << "dangerous" << endl;
    return 0;
}
