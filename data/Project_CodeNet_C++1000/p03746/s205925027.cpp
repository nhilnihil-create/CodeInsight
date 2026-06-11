#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
    int par[100002], rank[100002];
    
public:
    UnionFind(int n){
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }
    
    bool same(int i, int j){
        return par[i] == par[j];
    }
    
    void unite(int i, int j){
        if(same(i, j)) return;
        i = find(i), j = find(j);
        if(rank[i] < rank[j]) par[i] = j;
        else{
            par[j] = i;
            if(rank[i] == rank[j]) rank[i]++;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int a[100002], b[100002];
    vector<int> v[100002];
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    UnionFind uf(n + 1);
    vector<int> p1;
    int now = 1;
    while(true){
        bool ifend = true;
        for(int next : v[now]){
            if(!uf.same(now, next)){
                ifend = false;
                p1.push_back(next);
                uf.unite(now, next);
                now = next;
                break;
            }
        }
        if(ifend) break;
    }
    vector<int> p2;
    now = 1;
    while(true){
        bool ifend = true;
        for(int next : v[now]){
            if(!uf.same(now, next)){
                ifend = false;
                p2.push_back(next);
                uf.unite(now, next);
                now = next;
                break;
            }
        }
        if(ifend) break;
    }
    int l1 = p1.size();
    int l2 = p2.size();
    cout << l1 + l2 + 1 << endl;
    for(int i = l2 - 1; i >= 0; i--){
        cout << p2[i] << " ";
    }
    cout << 1 << " ";
    for(int i = 0; i < l1; i++){
        cout << p1[i] << " ";
    }
    cout << endl;
}