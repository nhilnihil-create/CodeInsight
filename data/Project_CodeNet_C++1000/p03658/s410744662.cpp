#include <bits/stdc++.h>
using namespace std;

//#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

signed main(){
    int n, k;
    cin >> n >> k;
    
    priority_queue<int> q;
    rep(i,n){
        int l; cin >> l;
        q.push(l);
    }
    
    int ans = 0;
    while(k--){
        ans += q.top();
        q.pop();
    }
    
    cout << ans << endl;
}