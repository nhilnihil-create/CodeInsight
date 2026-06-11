// "include" {{{
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#include <iomanip>
#include <tuple>
// }}}
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define int long long
#define setout(n,x) setw(n) << setfill(x)
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const long long mod = 1000000007;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    reps(i,n){
        int x;
        cin >> x;
        a[i] = a[i-1] + x;
    }
    int minv = LINF;
    reps(i,n-1){
        minv = min(minv,abs(a[n]-a[i]*2));
    }
    cout <<minv << '\n';
    return 0;
}
