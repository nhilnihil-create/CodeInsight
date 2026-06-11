#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
#define MOD 1000000007
int main() {
    int N,M;
    cin >> N >> M;
    if(abs(N-M)>1){
        cout << 0 << endl;
        return 0;
    }
    
    ll Nkaijo = 1;
    ll Mkaijo = 1;
    if(N==M){
        rep(i, 0, N){
            Nkaijo *= (i+1);
            Nkaijo %= MOD;
        }
        ll ans = (2*Nkaijo*Nkaijo)%MOD;
        cout << ans << endl;
    }else{
        rep(i, 0, N){
            Nkaijo *= (i+1);
            Nkaijo %= MOD;
        }
        rep(i, 0, M){
            Mkaijo *= (i+1);
            Mkaijo %= MOD;
        }
        ll ans = (Nkaijo*Mkaijo)%MOD;
        cout << ans << endl;
    }
    return 0;
}
