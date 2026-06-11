#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 100001;

int n, m;
vector <int> v[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector <int> path;
    path.push_back(1);
    vector <int> vis(n + 1);
    vis[1] = 1;
    auto expand = [&](){
        while(1){
            int ok = 1;
            for(auto &i : v[path.back()]){
                if(vis[i]) continue;
                path.push_back(i);
                vis[i] = 1;
                ok = 0;
                break;
            }
            if(ok) break;
        }
    };
    expand();
    reverse(path.begin(), path.end());
    expand();
    cout << path.size() << endl;
    for(auto &i : path) cout << i << " ";
    cout << endl;
}
