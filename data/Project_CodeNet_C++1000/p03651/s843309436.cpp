#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef long long ll;

const double PI = 3.1415926535897932384626;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;
const double EPS = 1e-10;

int main(){

    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    int ma = 0;

    rep(i, n){
        cin >> v[i];
        ma = max(ma, v[i]);
    }

    int g = v[0];

    for(int i = 1; i < n; i++){
        g = __gcd(g, v[i]);
    }

    if(k % g == 0 && k <= ma){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }





    return 0;
}
