#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class UnionFind{
    public:
    //親の番号を格納する。親だった場合は-(その集合のサイズ)
    vector<int> parent;

    //-1で初期化。最初はすべてバラバラ
    UnionFind(int N){
        parent = vector<int>(N,-1);
    }

    //Aがどのグループに属しているか(Aの根)を調べる
    int root(int A){
        if(parent[A] < 0) return A;
        return parent[A]=root(parent[A]);
    }

    //自分のいるグループの頂点数を調べる
    int size(int A){
        return -parent[root(A)];
    }

    //AとBをくっつける
    bool unite(int A, int B) {
    //AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        //既にくっついているからくっつけない
        if(A == B) return false; 

        //大きいほう(A)に小さいほう(B)をくっつける
        //大小が逆ならひっくり返す
        if(size(A) < size(B)) swap(A,B);

        //Aのサイズを更新する
        parent[A] += parent[B];
        //Bの親をAに変更する
        parent[B] = A;

        return true;
    }

    //AとBが同じグループならtrueを返す
    bool same(int A, int B){
        return root(A)==root(B);
    } 
};

vector<vector<int>> v(100010);
bool used[100010];

int dfs(int p){
    used[p] = true;
    int x = 0;
    for(auto i:v[p]){
        if(!used[i]){
            x ^= dfs(i) + 1;
        }
    }
    return x;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
    int n;
    cin>>n;
    UnionFind uni(n);
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
        uni.unite(a,b);
    }
    ll ans = dfs(0);
    cerr << ans << endl;
    for(int i=1;i<n;i++){
        if(!uni.same(0,i) && i==uni.root(i)){
            ans ^= 1;
        }
    }
    cerr << ans << endl;
    if(ans){
        cout << "Alice" << endl;
    }
    else cout << "Bob" << endl;
}