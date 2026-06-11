#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int64 h,w;
    cin >> w >> h;
    priority_queue<int64,vector<int64>,greater<int64>> p;
    priority_queue<int64,vector<int64>,greater<int64>> q;
    REP(i,w){
        int64 pi;
        cin >> pi;
        p.push(pi);
    }
    REP(i,h){
        int64 qi;
        cin >> qi;
        q.push(qi);
    }
    p.push(INF);
    q.push(INF);
    int64 ans = 0;
    while(h > 0 || w > 0){
        if(p.top() < q.top()){
            ans += p.top() * (h + 1);
            p.pop();
            w--;
        }else{
            ans += q.top() * (w + 1);
            q.pop();
            h--;
        }
        // cout << w << " " << h << endl;
    }
    // REP(i,h){
    //     ans += q.top();
    //     q.pop();
    // }
    // REP(j,w){
    //     ans += p.top();
    //     p.pop();
    // }
    ANS(ans);
    return 0;
}