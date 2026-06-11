#include <bits/stdc++.h>
using namespace std;

int color[100010] = {};
int old[100010];
vector<int> graph[100010];
int v[100010], d[100010], c[100010];


int main(){
    int n, m, q;
    cin >> n >> m;

    memset(old, -1, sizeof(old));

    int a, b;
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    cin >> q;
    for(int i = 0;i < q;i++){
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }

    queue<pair<int, pair<int, int> > > que;
    for(int p = q-1;p >= 0;p--){
        if(old[v[p]] < d[p]){
            que.push(make_pair(v[p], make_pair(d[p], c[p])));
            while(!que.empty()){
                int idx = que.front().first;
                int vi = que.front().second.first;
                int co = que.front().second.second;
                que.pop();
                old[idx] = vi;
                if(color[idx] == 0) color[idx] = co;

                if(vi == 0) continue;
                vi--;
                for(int i = 0;i < graph[idx].size();i++){
                    int next = graph[idx][i];
                    if(old[next] < vi){
                        que.push(make_pair(next, make_pair(vi, co)));
                    }
                }
            }
        }
    }

    for(int i = 0;i < n;i++){
        cout << color[i] << endl;
    }

    return 0;
}

