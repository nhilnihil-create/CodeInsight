#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;

vector<int> G[100010];
deque<int> dq;
bool used[100010];

void dfs(int v, int c){
    used[v] = true;
    for(int nv: G[v])if(!used[nv]){
        if(c == 0) dq.push_back(nv);
        else dq.push_front(nv);
        dfs(nv, c);
        return;
    }
    return;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, m){
        int a, b;
        scanf("%d%d", &a, &b);
        G[--a].push_back(--b);
        G[b].push_back(a);
    }
    dq.push_back(0);
    rep(i, n) used[i] = false;
    dfs(0, 0);
    dfs(0, 1);
    printf("%d\n", dq.size());
    for(int v: dq) printf("%d ", v+1);
}