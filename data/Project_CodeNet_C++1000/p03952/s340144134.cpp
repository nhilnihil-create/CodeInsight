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
    int n,x;
    cin >> n >> x;
    if(x == 1 || x == 2 * n - 1){
        cout << "No" << endl;
        return 0;
    }
    int ans[2 * n - 1];
    ans[n - 1] = x;
    int now = 1;
    for(int i = n - 2; i >= 0; i--){
        if(now == x) now++;
        ans[i] = now;
        now++;
    }
    now = 2 * n - 1;
    for(int i = n; i < 2 * n; i++){
        if(now == x) now--;
        ans[i] = now;
        now--;
    }
    cout << "Yes" << endl;
    REP(i,2 * n - 1){
        cout << ans[i] << endl;
    }
    return 0;
}