#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)

struct TREE{
    int N;
    vector<vector<int> >path;
    queue<int>Q;
    vector<int>depth;
    vector<int>A;
    vector<int>B;
    void init(int n){
        N = n;
        path = vector<vector<int> >(N);
        depth = vector<int>(N, 0);
        A.clear();
        B.clear();
    }
    TREE(int n){
        init(n);
    }
    void addPath(int a, int b){
        A.push_back(a);
        B.push_back(b);
        path[a].push_back(b);
        path[b].push_back(a);
    }
    void resetDepth(){
        for(int i=0; i<N; i++)depth[i] = -1;
    }
    void addRoot(int id){
        depth[id] = 0;
        Q.push(id);
    }
    void calcDepth(){
        while(!Q.empty()){
            int id = Q.front();
            Q.pop();
            for(int i=0;i<path[id].size();i++){
                int nxt = path[id][i];
                if(depth[nxt] < 0){
                    depth[nxt] = depth[id] + 1;
                    Q.push(nxt);
                }
            }
        }
    }
};

int main(){

    int N, K;
    cin >> N >> K;
    TREE tree(N+1);
    for(int i=0;i<N-1;i++){
        int a, b;
        cin >> a >> b;
        tree.addPath(a, b);
    }

    int mx = 0;
    if(K%2 == 0){
        K/=2;
        for(int i=1; i<=N; i++){
            tree.resetDepth();
            tree.addRoot(i);
            tree.calcDepth();
            int cnt = 0;
            for(int i=1;i<=N;i++){
                if(0<=tree.depth[i] && tree.depth[i]<=K)cnt++;
            }
            mx = max(mx, cnt);
        }
    }
    else{
        K/=2;
        for(int i=0;i<tree.A.size();i++){
            tree.resetDepth();
            tree.addRoot(tree.A[i]);
            tree.addRoot(tree.B[i]);
            tree.calcDepth();
            int cnt = 0;
            for(int i=1;i<=N;i++){
                if(0<=tree.depth[i] && tree.depth[i]<=K)cnt++;
            }
            mx = max(mx, cnt);
        }
    }
    cout << N - mx << endl;

    return 0;
}