#include <bits/stdc++.h>
using namespace std;
const int N=100010;
vector<int>vec[N];
int dfs(int u,int fa) {
    int re=0;
    for(int i=0; i<vec[u].size(); i++) {
        if(vec[u][i]!=fa) {
            re^=1+dfs(vec[u][i],u);
        }
    }
    return re;
}
int main() {
        int n;
        scanf("%d",&n);
        for(int i=1; i<n; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
    printf(dfs(1,0)?"Alice\n":"Bob\n");
    return 0;
}
