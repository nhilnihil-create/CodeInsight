#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N, M, A, ans;
    cin >> N >> M;
    queue<int> que[N];
    rep(i, N){
        rep(j, M) {
            cin >> A;
            que[i].push(A);
        }
    }
    priority_queue<pair<int, int> > pque[M];
    int cnt[M+1];
    bool used[M+1];
    fill_n(cnt, M+1, 0);
    fill_n(used, M+1, false);
    rep(i, N) cnt[que[i].front()]++;
    rep2(i, 1, M+1) pque[0].push(P(cnt[i], i));
    ans = pque[0].top().first;
    rep(i, M-1){
        P p = pque[i].top();
        int j = p.second;
        cnt[j] = 0;
        used[j] = true;
        rep(k, N){
            if(que[k].front() == j){
                while(used[que[k].front()]) que[k].pop();
                cnt[que[k].front()]++;
            }
        }
        rep2(k, 1, M+1) pque[i+1].push(P(cnt[k], k));
        ans = min(ans, pque[i+1].top().first);
    }
    cout << ans << endl;
}