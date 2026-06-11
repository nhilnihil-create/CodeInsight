//AC済 バチャコン用再提出
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int n;
    ll ans = 0;
    cin >> n;
    ll a[100050];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ans = a[1] - 1;
    a[1] = 1;
    ll now = 2;
    for(int i = 2; i <= n; i++){
        if(a[i] == now){
            now++;
            continue;
        }
        if(a[i] < now){
            continue;
        }
        ans += (a[i] - 1) / now;
    }
    cout << ans << endl;
    return 0;
}