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
    ll N,T;
    cin >> N >> T;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    ll ct=0,madif=0;
    ll mi=A[0];
    for(int i=1;i<N;i++){
        if(madif==A[i]-mi){
            ct++;
        }
        else if(madif<A[i]-mi){
            madif=A[i]-mi;
            ct=1;
        }
        mi=min(mi,A[i]);
    }
    cout << ct << endl;

    return 0;
}