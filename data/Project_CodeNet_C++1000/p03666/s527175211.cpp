#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    n--;
    for(int i = n; i >= 0; i--){
        ll r = a + i * d - (n - i) * c;
        ll l = r - (d - c) * n;
        if(b >= l && b <= r){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
