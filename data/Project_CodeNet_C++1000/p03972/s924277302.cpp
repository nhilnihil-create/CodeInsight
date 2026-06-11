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
    int w,h;
    cin >> w >> h;
    priority_queue<ll, vector<ll>, greater<ll>> que_p, que_q;
    que_p.emplace(LINF);
    que_q.emplace(LINF);
    REP(i,w){
        ll p;
        cin >> p;
        que_p.emplace(p);
    }
    REP(i,h){
        ll q;
        cin >> q;
        que_q.emplace(q);
    }
    ll ans = 0;
    ll now_w = w + 1, now_h = h + 1;
    while(!(que_p.size() == 1 && que_q.size() == 1)){
        if(que_p.top() < que_q.top()){
            ans += que_p.top() * now_h;
            que_p.pop();
            now_w--;
        }else{
            ans += que_q.top() * now_w;
            que_q.pop();
            now_h--;
        }
    }
    cout << ans << endl;
    return 0;
}