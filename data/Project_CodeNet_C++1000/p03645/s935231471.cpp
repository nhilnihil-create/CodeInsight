#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    long N,M;
    cin>>N>>M;
    vector<vector<long>> list(N);

    rep(i, M){
        long a,b;
        cin>>a>>b;
        list[a-1].push_back(b-1);
        list[b-1].push_back(a-1);
    }

    queue<long> que;
    vector<long> dis(N, -1);
    que.push(0);
    dis[0] = 0;
    while(!que.empty()){
        long v = que.front();
        que.pop();

        if(v == N-1 && dis[v] == 2){
            cout << "POSSIBLE" << endl;
            return 0;
        }

        for(long t : list[v]){
            if(dis[t] != -1) continue;
            que.push(t);
            dis[t] = dis[v]+1;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
