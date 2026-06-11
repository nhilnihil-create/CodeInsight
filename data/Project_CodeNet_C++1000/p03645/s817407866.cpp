#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vvi = vector<vector<int>> ;

struct unionfind{
    vector<int> r;

    unionfind(int n){
        r = vector<int>(n,-1); //r.at(i) iの根
    }

    int root(int x){
        if(r.at(x) < 0) return x;
        else return r.at(x) = root(r.at(x)); //xの根を返す
    }
    bool unite(int x,int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return false; //xとyの根が同じとき何もしない
        r.at(x) = ry;        //xの根にyの根を追加
        return true;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<set<int>> r(n);
    for(int ix=0;ix<m;ix++){
        int a,b; cin >> a >> b;
        a--; b--;
        r.at(a).insert(b);
        r.at(b).insert(a);
    }
    bool can = false;
    for(int ix=0;ix<n;ix++){
        if(r.at(ix).count(0) == true && r.at(n-1).count(ix) == true) can = true;
    }
    cout << (can == true ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}