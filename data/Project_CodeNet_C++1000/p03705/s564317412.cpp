#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    ll ans = (N-2)*B-(N-2)*A+1;
    if(ans<0) ans = 0;
    cout << ans << endl;
    return 0;
}