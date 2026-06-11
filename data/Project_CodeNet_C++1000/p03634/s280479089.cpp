#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    vector<P> v[N];
    for(int i=0; i<N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        v[a].push_back(P(b, c));
        v[b].push_back(P(a, c));
    }

    int Q, K;
    cin >> Q >> K;
    K--;
    int x[Q], y[Q];
    for(int i=0; i<Q; i++){
        cin >> x[i] >> y[i];
        x[i]--;y[i]--;
    }

    queue<pair<int, ll>> q;
    ll d[N];
    fill(d, d+N, -1);
    q.push(make_pair(K, (ll)0));
    while(!q.empty()){
        int now = q.front().first;
        d[now] = q.front().second;
        q.pop();
        for(auto next : v[now]){
            int p = next.first;
            ll cost = next.second;
            if(d[p] != -1) continue;
            q.push(make_pair(p, d[now]+cost));
        }
    }

    for(int i=0; i<Q; i++){
        ll ans = d[x[i]] + d[y[i]];
        cout << ans << endl;
    }

    return 0;
}
