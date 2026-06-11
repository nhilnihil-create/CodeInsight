#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

#define MAX 100000

signed main(){
    int n,m;
    cin >> n >> m;
    int cnt[MAX + 1] = {};
    int cntmod[m] = {};
    REP(i,n){
        int x;
        cin >> x;
        cnt[x]++;
        cntmod[x % m]++;
    }
    int ans = 0;
    int t = cntmod[0] / 2;
    ans += t;
    cntmod[0] -= 2 * t;
    if(m % 2 == 0){
        int t = cntmod[m / 2] / 2;
        ans += t;
        cntmod[m / 2] -= 2 * t;
        for(int i = 1; i < m / 2; i++){
            int t = min(cntmod[i], cntmod[m - i]);
            ans += t;
            cntmod[i] -= t;
            cntmod[m - i] -= t;
        }
    }else{
        for(int i = 1; i <= m / 2; i++){
            int t = min(cntmod[i], cntmod[m - i]);
            ans += t;
            cntmod[i] -= t;
            cntmod[m - i] -= t;
        }
    }
    for(int i = 1; i <= MAX; i++){
        int t = min(cnt[i] / 2, cntmod[i % m] / 2);
        ans += t;
        cntmod[i % m] -= t * 2;
    }
    cout << ans << endl;
    return 0;
}