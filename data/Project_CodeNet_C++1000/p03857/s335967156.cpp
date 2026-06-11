#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int N, K, L;

class UnionFind{
 public:
    int parent[200000];
    UnionFind(){
        for(int i = 0; i < N; i++){
            parent[i] = i;
        }
    }

    int root(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = root(parent[x]);
    }
    bool is_same_set(int x, int y){
        return root(x) == root(y);
    }
    void unite(int x, int y){
        parent[root(x)] = root(y);
    }
};


int main(){
    cin >> N >> K >> L;
    UnionFind road = UnionFind(), rail = UnionFind();
    for(int i = 0; i < K; i++){
        int x, y;
        cin >> x >> y;
        road.unite(x-1, y-1);
    }
    for(int i = 0; i < L; i++){
        int x, y;
        cin >> x >> y;
        rail.unite(x-1, y-1);
    }
    for(int i = 0; i < N; i++){
        road.root(i);
        rail.root(i);
    }
    map<pair<int, int>, int > m;
    for(int i = 0; i < N; i++){
        m[make_pair(road.root(i), rail.root(i))]++;
    }
    for(int i = 0; i < N; i++){
        if(i) cout << " ";
        cout << m[make_pair(road.root(i), rail.root(i))];
    }
    cout << endl;
    

}