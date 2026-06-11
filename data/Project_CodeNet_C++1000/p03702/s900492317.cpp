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
vector<ll> H;
ll N,A,B;

bool pos(ll K){
    ll num=0;
    bool jg=false;
    for(int i=0;i<N;i++){
        if(H[i]-K*B<=0)continue;
        else{
            num+=ceil((double)(H[i]-K*B)/A);
            if(num>INF) jg=true;
        }
    }
    return ((num<=K||jg) ? true : false);
}

int main() {
    cin >> N >> A >> B;
    A-=B;
    H.assign(N,0);
    for(int i=0;i<N;i++) cin >> H[i];
    ll ux=INF,bx=0;
    while(ux>bx+1){
        ll mid = (ux+bx)/2;
        if(pos(mid)) ux = mid;
        else bx = mid;
    }

    cout << ux << endl;

    return 0;
}