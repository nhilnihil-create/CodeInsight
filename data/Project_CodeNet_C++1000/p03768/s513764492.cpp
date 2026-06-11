#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n, m; cin >> n >> m;

    // Get tree
    int a, b;
    vector<vector<int>> edge(n, vector<int>{});
    for(int i=0; i<m; i++){
        cin >> a >> b; a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    // Get all paint query at the fisrt for reverse
    vector<vector<int>> paint_query;
    int q; cin >> q;
    int v, d, c;
    for(int i=0; i<q; i++){
        cin >> v >> d >> c; v--;
        paint_query.push_back(vector<int>{v, d, c});
    }
    reverse(paint_query.begin(), paint_query.end());

    // 0-10 depth BFS
    vector<int> colors(n, 0);
    vector<int> paint_depth(n, -1);
    for(int i=0; i<q; i++){
        v = paint_query[i][0];
        d = paint_query[i][1]; 
        c = paint_query[i][2];
        queue<vector<int>> que;
        // vector{from, now, distance}
        que.push(vector<int>{-1, v, d});
        while(!que.empty()){
            vector<int> val = que.front(); que.pop();
            int from = val[0];
            int now = val[1];
            int depth = val[2];
            if(depth <= paint_depth[now]){continue;}
            paint_depth[now] = max(paint_depth[now] ,depth);
            if(colors[now] == 0){
                colors[now] = c;
            }
            for(int j=0; j<(int)edge[now].size(); j++){
                int to = edge[now][j];
                if(from == to){continue;}
                if(depth <= 0){continue;}
                que.push(vector<int>{now, to, depth-1});
            }
        }
    }
    for(auto& v:colors){
        cout << v << endl;
    }
    return 0;
}