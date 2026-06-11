#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    map<pair<int, int>, ll> m;
    vector<vector<int> > v(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[b].push_back(a);
        v[a].push_back(b);
        int k;
        cin >> k;
        if(a < b){
            m[make_pair(a, b)] = k;
        }else{
            m[make_pair(b, a)] = k;
        }
    }

    int q, k;
    cin >> q >> k;
    k--;
    int x[q], y[q];
    for(int i = 0; i < q; i++){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    ll dis[n];
    for(int i = 0; i < n; i++){
        dis[i] = 0;
    }

    queue<int> t;
    t.push(k);
    while(!t.empty()){
        int o = t.front();
        t.pop();
        for(int i = 0; i < v[o].size(); i++){
            if(o < v[o][i]){
                auto itr = m.find(make_pair(o, v[o][i]));
                if(dis[v[o][i]] == 0){
                    dis[v[o][i]] = dis[o] + itr->second;
                    t.push(v[o][i]);
                } 
            }else{
                auto itr = m.find(make_pair(v[o][i], o));
                if(dis[v[o][i]] == 0){
                    dis[v[o][i]] = dis[o] + itr->second;
                    t.push(v[o][i]);
                }
            }
        }
    }

    for(int i = 0; i < q; i++){
        cout << dis[x[i]] + dis[y[i]] << endl;
    }
}