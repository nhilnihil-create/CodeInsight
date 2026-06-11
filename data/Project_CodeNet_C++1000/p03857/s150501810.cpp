#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1e9;
int MOD = 1e9+7;
typedef pair<int,int> P;
const int MAX_N = 200000;
struct UnionFind{
    int par[MAX_N];
    void init(int n){
        for(int i = 0;i < n;i++){
            par[i] = i;
        }
    }
    int root(int x){
        if(par[x] == x)return x;
        else return par[x] = root(par[x]);
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
    void unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x == y)return;
        par[y] = x;
    }
};
main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,K,L;
    cin >> N >> K >> L;
    UnionFind r,t;
    r.init(N);
    t.init(N);
    for(int i = 0;i < K;i++){
        int a,b;
        cin >> a >> b;
        r.unite(a-1,b-1);
    }
    for(int i = 0;i < L;i++){
        int a,b;
        cin >> a >> b;
        t.unite(a-1,b-1);
    }
    map<P,int> mp;
    for(int i = 0;i < N;i++){
        mp[P(r.root(i),t.root(i))]++;
    }
    for(int i = 0;i < N;i++){
        cout << mp[P(r.root(i),t.root(i))] << " ";
    }
    cout << endl;
}