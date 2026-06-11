#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    ll a[n];
    REP(i,n){
        cin >> a[i];
    }
    ll ans = a[0] - 1, now = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == now + 1) now++;
        else ans += (a[i] - 1) / (now + 1);
    }
    cout << ans << endl;
    return 0;
}