#include <iostream>
#include<sstream>
#include<string>
#include<vector>
#include <cmath>
#include <limits>
#include <queue>
#include<algorithm>
#include<cstring>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <memory>
#include <numeric>
#include <type_traits>
 
using namespace std;
 
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
typedef long long ll;
const int maxN = 1e5;
const ll maxV = 1e14;
const int NIL = -1;
const int white = 0, gray = 1;
ll TRAV[maxN];
int COLOR[maxN];


struct Edge{
    int from, to;
    ll length;
};


struct Node{
    vector<Edge> e;
};
Node T[maxN];

void dfs(int k){
    rep(i,T[k].e.size()){
        Edge e = T[k].e[i];
        if (COLOR[e.to] == gray) continue;
        else{
            TRAV[e.to] = TRAV[k]+e.length;
            COLOR[e.to] = gray;
            dfs(e.to);
        }
    }
}


int main() {
    int n;
    cin >> n;
    rep(i,n){
        COLOR[i] = white;
    }
    int a,b; ll c;
    Edge e;
    rep(i,n-1){
        cin >> a >> b >> c;
        --a; --b;
        e.from = a; e.to = b; e.length = c;
        T[a].e.push_back(e);
        e.from = b; e.to = a;
        T[b].e.push_back(e);
    }
    int q,k;
    cin >> q >> k;
    --k;
    TRAV[k] = 0;
    COLOR[k] = gray;
    dfs(k);
    int x[q],y[q];
    rep(i,q){
        cin >> x[i] >> y[i];
    }
    rep(i,q){
        cout << TRAV[x[i]-1]+TRAV[y[i]-1] << endl;
    }
    return 0;
}