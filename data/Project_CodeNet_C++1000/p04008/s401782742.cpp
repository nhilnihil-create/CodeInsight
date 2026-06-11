#include<bits/stdc++.h>
using namespace std;

const int SIZE = 100001;
priority_queue<pair<int, int> > D;//pair(depth, id)j
int P[SIZE];//parent, depth
vector<int> C[SIZE];//children
set<int> S;
void make_D(int id = 1, int depth = 0){
    D.push(make_pair(depth, id));
    for (int i = 0; i < C[id].size(); i++){
        make_D(C[id][i], depth + 1);
    }
}
void add_S(int x){
    if (S.find(x) != S.end())return;
    S.insert(x);
    for (int i = 0; i < C[x].size(); i++){
        add_S(C[x][i]);
    }
}
int main(){
    int N, K; cin >> N >> K;
    int ans = 0;
    for (int i = 1; i <= N; i++){
        int ai; cin >> ai;
        C[ai].push_back(i);
        P[i] = ai;
    }
    if (P[1] != 1){
        C[P[1]].erase(C[P[1]].begin());
        P[1] = 1;
        ans++;
    }
    else
        C[1].erase(C[1].begin());
    
    make_D();
    while ((!D.empty()) && D.top().first > K)
    {
        pair<int, int> p = D.top();D.pop();
        if (S.find(p.second) == S.end()){
            int x = p.second;
            for (int i = 1; i < K; i++){
                x = P[x];
            }
            add_S(x);
            ans++;
        }
    }
    cout << ans << endl;
}