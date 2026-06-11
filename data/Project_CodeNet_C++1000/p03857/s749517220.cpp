#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
struct UnionFind {
    vector<int> data;
    // data[i]はマイナスなら連結成分の要素数を表す
    //プラスならば親ノードを表す
    UnionFind(int sz) { data.assign(sz, -1); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y)
            return (false);
        if(data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int k) {
        if(data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }
    bool isSame(int x, int y) { return find(x) == find(y); }
    ll size(int k) { return (-data[find(k)]); }
};
int main() {
    int n, k, l;
    cin >> n >> k >> l;
    UnionFind uf1(n), uf2(n);
    vector<set<int>> s1(n), s2(n);
    for(size_t i = 0; i < k; i++) {
        int p, q;
        cin >> p >> q;
        p--, q--;
        uf1.unite(p, q);
    }
    for(int i = 0; i < n; i++) {
        s1[uf1.find(i)].insert(i);
    }

    for(int i = 0; i < l; i++) {
        int p, q;
        cin >> p >> q;
        p--, q--;
        uf2.unite(p, q);
    }
    for(int i = 0; i < n; i++) {
        s2[uf2.find(i)].insert(i);
    }
  map<pair<int,int>,int> mp;
  for(int i=0;i<n;i++){
    mp[make_pair(uf1.find(i),uf2.find(i))]++;
  }
  for(int i=0;i<n;i++){
    cout<<mp[make_pair(uf1.find(i),uf2.find(i))]<<" ";
  }
  cout<<endl;
}

