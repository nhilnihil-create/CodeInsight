#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
struct graph{
    int ob;
    int di;
};
int main(){
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    vector<vector<graph>> d(N + 1, vector<graph>(0));
    for (int i = 1; i <= N - 1; i++){
        cin >> a.at(i) >> b.at(i) >> c.at(i);
        graph g = {b.at(i), c.at(i)}, h = {a.at(i), c.at(i)};
        d.at(a.at(i)).push_back(g);
        d.at(b.at(i)).push_back(h);
    }
    int Q, K;
    cin >> Q >> K;
    vector<int> x(Q + 1), y(Q + 1);
    for (int i = 1; i <= Q; i++){
        cin >> x.at(i) >> y.at(i);
    }
    
    vector<int64_t> KY(N + 1, INF);
    KY.at(0) = 0;
    d.at(0).push_back({K, 0});
    stack<int> q;
    q.push(0);
    while (!q.empty()){
        int st = q.top();
        q.pop();
        for(int i = 0; i < d.at(st).size(); i++){
            int st_1 = d.at(st).at(i).ob;
            int ky_1 = d.at(st).at(i).di;
            if (KY.at(st_1) != INF) continue;
            else{
                q.push(st_1);
                KY.at(st_1) = KY.at(st) + ky_1;
            }
        }
    }
    for (int i = 1; i <= Q; i++){
        cout << KY.at(x.at(i)) + KY.at(y.at(i)) << endl;
    }
}