#include <bits/stdc++.h>

using namespace std;
#define lint long long
typedef pair<lint, lint> P;

int main() {
    int W, H;
    
    cin >> W >> H;
    
    vector<lint> p(W);
    vector<lint> q(H);
    priority_queue<P,vector<P>, greater<P>> que;
    
    for(int i = 0; i < W ; ++i){
        cin >> p[i];
        que.push(make_pair(p[i], 0));
    }
    for(int i = 0; i < H; ++i){
        cin >> q[i];
        que.push(make_pair(q[i], 1));
    }
    
    int a = W + 1;
    int b = H + 1;
    
    lint cost = 0;
    
    while(!que.empty()){
        auto p = que.top(); que.pop();
        
        if(!p.second){
            cost += p.first * b;
            a--;
        } else {
            cost += p.first * a;
            b--;
        }
    }
    
    cout << cost << endl;
}