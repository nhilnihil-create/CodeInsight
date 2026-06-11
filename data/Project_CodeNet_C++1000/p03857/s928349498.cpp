#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> P;
struct UF{
    vector<int> par, rank, size;

    void init(int n){
        par.assign(n, 0);
        rank.assign(n, 0);
        size.assign(n, 1);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x != y){
            if(rank[x] < rank[y]){
                par[x] = y;
                size[y] += size[x];
            }else{
                par[y]=x;
                size[x] += size[y];
                if(rank[x]==rank[y]) rank[x]++;
            }
        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    int get_size(int x){
        return size[find(x)];
    }
};
int main(void){
    int n, k, l;
    UF road, train;
    map<P, int> p;
    cin >> n >> k >> l;
    road.init(n);
    train.init(n);
    for(int i=0;i<k;i++){
        int p, q;
        cin >> p >> q;
        road.unite(--p, --q);
    }
    for(int i=0;i<l;i++){
        int r, s;
        cin >> r >> s;
        train.unite(--r, --s);
    }
    for(int i=0;i<n;i++){
        p[P(road.find(i), train.find(i))]++;
    }
    for(int i=0;i<n;i++){
        cout << p[P(road.find(i), train.find(i))] << " ";
    }
    cout << endl;
}
