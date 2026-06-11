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
    string a;
    cin >> a;
    ll n = a.size();
    ll cnt[26] = {};
    ll ans = n * (n - 1) / 2;
    REP(i,n){
        int t = a[i] - 'a'; 
        ans -= cnt[t];
        cnt[t]++;
    }
    cout << ans + 1 << endl;
    return 0;
}