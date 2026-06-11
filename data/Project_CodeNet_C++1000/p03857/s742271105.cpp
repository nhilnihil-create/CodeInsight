#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct dsu{
    int p[200002], sz[200002];
    void init(int n){
        for(int i=1;i<=n;i++) p[i] = i, sz[i] = 1;
    }
    int root(int a){
        return p[a] == a?a:(p[a]=root(p[a]));
    }
    void merge(int a, int b){
        a = root(a), b = root(b);
        if(a != b){
            sz[b] += sz[a];
            p[a] = b;
        }
    }
}d1, d2;
map<pii, int> dp;

int main(){
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);
    d1.init(n), d2.init(n);
    for(int i=1;i<=k;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        d1.merge(a, b);
    }
    for(int i=1;i<=l;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        d2.merge(a, b);
    }
    for(int i=1;i<=n;i++) dp[make_pair(d1.root(i), d2.root(i))]++;
    for(int i=1;i<=n;i++) printf("%d ", dp[make_pair(d1.root(i), d2.root(i))]);
}