#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
    int n, m, R;
    cin >> n >> m >> R;
    vi r(R);
    rep(i, R) {
        cin >> r[i];
        --r[i];
    }
    sort(r.begin(), r.end());
    vector<vector<pair<int, int> > > G(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }


    vector<vector<int> > Gr(R, vi(R));
    rep(i, R) {
        queue<int> Q;
        Q.push(r[i]);
        vi dis(n, INT_MAX);
        dis[r[i]] = 0;
        while(!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for(auto next:G[now]){
                if(dis[next.first] != INT_MAX) {
                    if(dis[next.first] > dis[now] + next.second) {
                        Q.push(next.first);
                        dis[next.first] = dis[now] + next.second;
                    } else if(dis[next.first] + next.second < dis[now]) {
                        dis[now] = dis[next.first] +next.second;
                        Q.push(now);
                        break;
                    } else {
                        continue;
                    }
                }
                dis[next.first] = dis[now] + next.second;
                Q.push(next.first);
            }
        }
        rep(j, R) {
            Gr[i][j] = dis[r[j]];
        }
        /*rep(j, n) {
            cout << dis[j] << ' ';
        }
        cout << endl;*/
    }


    int ans = INT_MAX;
    vi vec(R);
    rep(i, R) {
        vec[i] = i;
    }

    do{
        int d=0;
        rep(i, R-1) {
            d += Gr[vec[i]][vec[i+1]];
        }
        ans = min(ans, d);
    } while(next_permutation(vec.begin(), vec.end()));

    cout << ans << endl;
}