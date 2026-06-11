#include <bits/stdc++.h>
using namespace std;

class UnionFind{
public:
    vector<int> tree;

    void init(){
        for(int i = 0;i < tree.size();i++){
            tree[i] = i;
        }
    }

    UnionFind(int n){
        n++;
        tree.resize(n);
        init();
        return;
    }

    int root(int i){
        if(tree[i] == i) return i;
        return tree[i] = root(tree[i]);
    }

    bool unite(int i, int j){
        i = root(i);
        j = root(j);
        if(i == j) return false;
        tree[j] = i;
        return true;
    }

    bool same(int i, int j){
        return root(i) == root(j);
    }
};

int main(){
    int n, k, l;
    cin >> n >> k >> l;
    UnionFind uf1(n);
    UnionFind uf2(n);

    int a, b;
    for(int i = 0;i < k;i++){
        cin >> a >> b;
        uf1.unite(a, b);
    }

    for(int i = 0;i < l;i++){
        cin >> a >> b;
        uf2.unite(a, b);
    }

    map<int, int> mp[200010];
    for(int i = 0;i < n;i++){
        mp[uf1.root(i+1)][uf2.root(i+1)]++;
    }

    for(int i = 0;i < n;i++){
        cout << mp[uf1.root(i+1)][uf2.root(i+1)];
        if(i < n-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
}
