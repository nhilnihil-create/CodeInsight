#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[100002];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = a[0] - 1;
    ll r = 1;
    for(int i = 1; i < n; i++){
        ans += (a[i] - 1) / (r + 1);
        if(a[i] == r + 1) r++;
    }
    cout << ans << endl;
}