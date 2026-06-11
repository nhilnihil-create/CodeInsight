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
    ll N,x;
    cin >> N >> x;

    vector<ll> A(N);
    ll ans=0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        ans+=A[i];
    }
    vector<ll> mi(N);
    for(int i=0;i<N;i++) mi[i]=A[i];

    for(int k=0;k<N;k++){
        ll tmp=x*k;
        for(int i=0;i<N;i++){
            mi[i]=min(mi[i],A[(i-k+N)%N]);
            tmp+=mi[i];
        }
        ans=min(ans,tmp);
    }
    cout << ans << endl;

    return 0;
}