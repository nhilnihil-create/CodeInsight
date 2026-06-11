#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    int x[100002];
    for(int i = 0; i < n; i++) cin >> x[i];
    ll k = 0;
    ll ans = 1;
    for(int i = 0; i < n; i++){
        k++;
        ans = (ans * k) % MOD;
        if(k * 2 - 1 > x[i]) k--;
    }
    cout << ans << endl;
}