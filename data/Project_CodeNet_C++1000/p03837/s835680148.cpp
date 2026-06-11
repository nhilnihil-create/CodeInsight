#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
#include <climits>
using namespace std;

long long n;
vector<vector<pair<long long, long long> > > g;
set<pair<long long, long long> > st;

void dijkstra(long long s){
    vector<int> d (n, 1e9),  p(n, -1);
    d[s] = 0;
    set < pair<int,int> > q;
    q.insert (make_pair (d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase (q.begin());

        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
                len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase (make_pair (d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert(make_pair (d[to], to));
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(p[i] == -1) continue;
        long long a = max(i, p[i]), b = min(i, p[i]);
        st.insert({a, b});
    }
}

int main(){
    long long m;
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; ++i){
        long long fr, to, w;
        cin >> fr >> to >> w;
        fr--, to--;
        g[fr].push_back({to, w});
        g[to].push_back({fr, w});
    }

    for(int i = 0; i < n; ++i) dijkstra(i);

    //for(auto i = st.begin(); i != st.end(); ++i) cout << i->first << " " << i->second << endl;
    cout << m - st.size();
    
}
