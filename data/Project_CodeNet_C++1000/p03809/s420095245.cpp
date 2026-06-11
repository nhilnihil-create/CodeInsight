#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

ll N;
vector<vector<ll>> edges;
vector<ll> A;
ll root;

ll dfs(ll now, ll pre){
    bool leaf = 1;
    vector<ll> num;
    for(ll next : edges[now]){
        if(next == pre) continue;
        leaf = 0;
        num.push_back(dfs(next, now));
    }
    if(leaf) return A[now];
    sort(num.begin(), num.end());
    if(num[0] == -1) return -1;
    reverse(num.begin(), num.end());
    ll sum = accumulate(num.begin(), num.end(), 0);
    ll ret = 2 * A[now] - sum;
    ll to_child = A[now] - ret;
    if(ret < 0 || to_child < 0) return -1;
    ll possible;
    if(num[0] >= sum - num[0]) possible = sum - num[0];
    else if(num.size() == 2) possible = min(num[0], num[1]);
    else possible = sum / 2;
    if(to_child <= possible) return ret;
    else return -1;
}

void init(){
    cin >> N;
    A.resize(N);
    edges.resize(N);
    for(ll &a : A) cin >> a;
    for(ll i = 1; i < N; i++){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(ll i = 0; i < N; i++){
        if(edges[i].size() > 1){
            root = i;
            break;
        }
    }
}

void solve(){
    cout << ((N == 2 && A[0] == A[1]) || !dfs(root, -1) ? "YES" : "NO") << endl;
}

int main(){
    init();
    solve();
    return 0;
}
