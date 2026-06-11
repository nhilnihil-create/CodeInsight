#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > Pi;
//親が繋げているノードのANDをとることで処理ができる(何個つながっているのか)
struct UF
{
    int parent[200005];
    int size[200005];
    UF() { for(int i = 0; i < 200005; i++) parent[i] = i, size[i] = 1; }
    int root(int n) { return parent[n] = (parent[n] == n ? n : root(parent[n])); }
    void unite(int a, int b) { a = root(a), b = root(b); parent[a] = b; size[b] += size[a]; }
    int get_size(int n) { return (size[root(n)]); }
};
UF tree1, tree2;
int main()
{
    int N, K, L;
    map < Pi , int > mp;
    cin >> N >> K >> L;
    for(int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b; --a, --b;
        tree1.unite(a, b);
    }
    for(int i = 0; i < L; i++) {
        int a, b;
        cin >> a >> b; --a, --b;
        tree2.unite(a, b);
    }
    for(int i = 0; i < N; i++) mp[Pi(tree1.root(i),tree2.root(i))]++;
    for(int i = 0; i < N; i++) {
        cout << mp[Pi(tree1.root(i), tree2.root(i))];
        if(i < N - 1) cout << " ";
        else cout << endl;
    }
    return (0);
}
