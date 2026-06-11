#include<iostream>
#include<vector>
#include<map>
using namespace std;

class DisjointSet{
  public:
    vector<int> rank, p;

    DisjointSet(){}
    DisjointSet(int size){
        rank.resize(size, 0);
        p.resize(size, 0);
        for(int i = 0; i < size; i++) makeSet(i);
    }

    void makeSet(int x){
        p[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y){
        return findSet(x) == findSet(y);
    }
    
    void unite(int x, int y){
        link(findSet(x), findSet(y));
    }

    void link(int x, int y){
        if(rank[x] > rank[y]){
            p[y] = x;
        }else{
            p[x] = y;
            if(rank[x] == rank[y]){
                rank[y]++;
            }
        }
    }

    int findSet(int x){
        if(x != p[x]){
            // path compression
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
};

int main(){
    int n, k, l;
    cin >> n >> k >> l;

    DisjointSet road(n), train(n);

    int p, q, r, s;
    for(int i = 0; i < k; i++){
        cin >> p >> q;
        p--, q--;
        road.unite(p, q);
    }

    for(int i = 0; i < l; i++){
        cin >> r >> s;
        r--, s--;
        train.unite(r,s);
    }

    vector<int> ro(n), tr(n);
    for(int i = 0; i < n; i++)  ro[i] = road.findSet(i);
    for(int i = 0; i < n; i++)  tr[i] = train.findSet(i);

    map<int, map<int, int>> m;
    for(int i = 0; i < n; i++)  m[ro[i]][tr[i]]++;

    for(int i = 0; i < n; i++)  cout << m[ro[i]][tr[i]] << " \n"[i == n-1];
    
    return 0;
}