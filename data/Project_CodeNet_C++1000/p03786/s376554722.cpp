#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define PI (acos(-1.0))
#define MODN 1000000007
#define MODN2 998244353
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    int n;
    cin >> n;

    vector<ll> a(n);

    rep(i, n){
        cin >> a[i];
    }

    sort(ALL(a));

    vector<ll> acc(n);
    acc[0] = a[0];

    for(int i = 1; i < n; i++){
        acc[i] = acc[i - 1] + a[i];
    }

    vector<bool> able(n, false);
    able[n - 1] = true;

    rep(i, n - 1){
        if(a[i + 1] <= acc[i] * 2){
            able[i] = true;
        }
    }

    int ans = 0;

    for(int i = n - 1; i >= 0; i--){
        if(able[i]){
            ans++;
        }else{
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
