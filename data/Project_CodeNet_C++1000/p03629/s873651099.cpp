#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;

const ll INF = 5e15;

vector<vector<ll>> pos(26);
vector<ll> len(2e5 + 10, -1);
string S;
ll N;

ll dfs(ll now){
    if(now > N) return len[now] = -1;
    if(len[now] != -1) return len[now];
    ll nxt = now;
    for(ll i = 0; i < 26; i++){
        auto ite = lower_bound(pos[i].begin(), pos[i].end(), now);
        nxt = max(nxt, *ite);
    }
    return len[now] = dfs(nxt + 1) + 1;
}

int main(){
    cin >> S;
    N = S.size();
    for(ll i = 0; i < S.size(); i++) pos[S[i] - 'a'].push_back(i);
    for(auto &v : pos) v.push_back(N);
    for(ll i = 0; i < N; i++) dfs(i);
    ll idx = 0;
    string ans = "";
    while(idx < N){
        for(ll i = 0; i < 26; i++){
            auto ite = lower_bound(pos[i].begin(), pos[i].end(), idx);
            if(len[*ite + 1] + 1 <= len[idx]){
                ans += 'a' + i;
                idx = *ite + 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
