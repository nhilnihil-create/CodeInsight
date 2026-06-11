#include <bits/stdc++.h>
using namespace std;

int N, A[100000];
vector<int> edges[100000];

int64_t up[100000];

void fail(){
    cout << "NO" << endl;
    exit(0);
}

void dfs(int i, int par){
    if(par >= 0 && edges[i].size() == 1){
        up[i] = A[i];
        return;
    }
    vector<int64_t> vs;
    int64_t s = 0, mx = 0;
    for(int j : edges[i]) if(j != par){
        dfs(j, i);
        vs.push_back(up[j]);
        s += up[j];
        mx = max(mx, up[j]);
    }
    int64_t p = s-A[i], u = 2*A[i]-s;
    if(p < 0 || u < 0) fail();
    if(mx-u > p) fail();
    up[i] = u;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    for(int i=0; i<N; i++) if(edges[i].size() == 1){
        dfs(i, -1);
        if(up[i] != A[i]) fail();
        cout << "YES" << endl;
        return 0;
    }
}