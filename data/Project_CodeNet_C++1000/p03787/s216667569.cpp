#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> dist(n,0);
    vector<vector<int>> edges(n);
    
    for (int i = 0;i < m;++i) {
        int u,v;
        scanf("%d%d",&u,&v);
        u--;v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    ll a = 0,b = 0,c = 0,ans = 0;
    for (int i = 0;i < n;++i) if (dist[i] == 0) {
        if (edges[i].size() == 0) {
            c++;
            continue;
        }
        queue<int> que;
        que.push(i);
        bool nibu = true;
        while (!que.empty()) {
            int t = que.front();que.pop();
            for (int j : edges[t]) {
                if (dist[j]) {
                    if (dist[j]%2 == dist[t]%2) nibu = false;
                } else {
                    dist[j] = dist[t]+1;
                    que.push(j);
                }
            }
        }
        if (nibu) a++;
        else b++;
    }
    ans += a*a*2+b*b+b*a*2+(2*n*c-c*c);
    cout << ans << endl;
}