#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()

typedef long long ll;

using namespace std;
//using namespace boost::multiprecision;

int main(){

    int n;
    cin >> n;
    ll a,b;
    cin >> a >> b;

    vector<ll> x;

    rep(i,n){
        ll tmp;
        cin >> tmp;
        x.pback(tmp);
    }

    ll ans = 0;

    rep(i,n - 1){
        if((x[i + 1] - x[i]) * a < b){
            ans += (x[i + 1] - x[i]) * a;
        }else{
            ans += b;
        }
    }

    cout << ans << endl;

    return 0;
}