#include <iostream>
#include <vector>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
using ll = long long;
using namespace std;
const ll mod = 1000000007;

int main() {
    ll n,m;
    cin >> n >> m;
 
    ll a = min(n,m/2);
    ll b = (m - 2 * a) / 4;

    cout << a + b << endl;
 
    return 0;
}