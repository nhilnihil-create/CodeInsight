#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

const ll INF = 1LL<<60;
const ll MOD = 1000000007;

//cout << fixed << setprecision(10);

int main() {
    ll N,M;
    cin >> N >> M;
    vector<ll> X(N),Y(M);
    for(int i=0;i<N;i++) cin >> X[i];
    for(int i=0;i<M;i++) cin >> Y[i];
    ll sumx = 0, sumy = 0;
    for(int i=0;i<N;i++){
        ll tmp = X[i]*(2*(i+1)-N-1);
        if(tmp<0) tmp=(tmp+(llabs(tmp)/MOD+1)*MOD)%MOD;
        else tmp%=MOD;
        sumx=(sumx+tmp)%MOD;
    }
    for(int i=0;i<M;i++){
        ll tmp = Y[i]*(2*(i+1)-M-1);
        if(tmp<0) tmp=(tmp+(llabs(tmp)/MOD+1)*MOD)%MOD;
        else tmp%=MOD;
        sumy=(sumy+tmp)%MOD;
    }
    cout << (sumx*sumy)%MOD << endl;
    

    return 0;
}