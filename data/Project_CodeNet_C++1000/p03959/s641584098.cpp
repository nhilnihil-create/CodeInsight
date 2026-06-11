#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    ll t[100002], a[100002];
    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) if(i == 0 || t[i] > t[i - 1]) if(a[i] < t[i]){
        cout << 0 << endl;
        return 0;
    }
    for(int i = n - 1; i >= 0; i--) if(i == n - 1 || a[i] > a[i + 1]) if(t[i] < a[i]){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for(int i = 0; i < n; i++){
        if(t[i] == t[i - 1] && a[i] == a[i + 1]) ans = ans * min(t[i], a[i]) % MOD;
    }
    cout << ans << endl;
}