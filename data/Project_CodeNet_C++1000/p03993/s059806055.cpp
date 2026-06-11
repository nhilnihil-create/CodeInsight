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

    vector<int> a(n);

    rep(i, n){
        int tmp;
        cin >> tmp;
        tmp--;

        a[i] = tmp;
    }

    int ans = 0;

    rep(i, n){
        if(a[a[i]] == i) ans++;
    }

    cout << ans / 2 << endl;
    return 0;
}
