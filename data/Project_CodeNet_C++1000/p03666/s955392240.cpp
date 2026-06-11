#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll dif = abs(a - b);
    for(ll i = 0; i <= n - 1; i++){
        ll lar = d * i - c * (n - 1 - i);
        if(lar >= dif && lar - dif <= (d - c) * (n - 1)){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}