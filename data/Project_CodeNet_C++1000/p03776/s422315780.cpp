#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;

ll com[52][52];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    com[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            com[i][j] = com[i - 1][j];
            if(j) com[i][j] += com[i - 1][j - 1];
        }
    }
    ll v[52];
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v, v + n, greater<ll>());
    ll s = 0;
    for(int i = 0; i < a; i++) s += v[i];
    cout << fixed << setprecision(15) << s * 1.0 / a << endl;
    if(v[0] == v[a - 1]){
        int k;
        for(k = 0; k < n; k++){
            if(v[k] != v[0]) break;
        }
        ll ans = 0;
        for(int i = a; i <= min(k, b); i++) ans += com[k][i];
        cout << ans << endl;
        return 0;
    }
    int p = 0;
    for(int i = a - 1; i >= 0; i--){
        if(v[i] == v[a - 1]) p++;
    }
    int q = 0;
    for(int i = a; i < n; i++){
        if(v[i] == v[a - 1]) q++;
    }
    cout << com[p + q][p] << endl;
}
