#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

signed main(){
    map<int, int> sticks;
    int n;
    cin >> n;
    rep(i,n){
        int a;
        cin >> a;
        sticks[a]++;
    }
    priority_queue<int> q;
    for(auto p : sticks){
        rep(i,min<int>(p.second/2, 2)) q.push(p.first);
    }
    
    if(q.size() <= 1){
        cout << 0 << endl;
    }else{
        int ans = q.top();
        q.pop();
        ans *= q.top();
        cout << ans << endl;
    }
}