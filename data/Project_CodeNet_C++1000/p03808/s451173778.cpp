#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll a[100005];
    ll s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    if(s % (n * (n + 1) / 2)){
        cout << "NO" << endl;
        return 0;
    }
    ll l = s / (n * (n + 1) / 2);
    ll k = 0;
    for(int i = 0; i < n; i++){
        ll d = a[i] - a[(i + 1) % n] + l;
        if(d < 0 || d % n != 0){
            cout << "NO" << endl;
            return 0;
        }
        k += d / n;
    }
    if(k == l) cout << "YES" << endl;
    else cout << "NO" << endl;
}
