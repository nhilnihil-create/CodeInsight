#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> piipi;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

struct p{
    int p[200005];
    int root(int a){
        return p[a] == a?a:(p[a]=root(p[a]));
    }
    void merge(int a, int b){
        a = root(a), b = root(b);
        if(a != b) p[a] = b;
    }
}p1,p2;

map<pii, int> dp;
int main(){
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);
    for(int i=1;i<=n;i++){
        p1.p[i] = i;
        p2.p[i] = i;
    }
    for(int i=1;i<=k;i++){
        int p, q;
        scanf("%d%d", &p, &q);
        p1.merge(p, q);
    }
    for(int i=1;i<=l;i++){
        int p, q;
        scanf("%d%d", &p, &q);
        p2.merge(p, q);
    }
    for(int i=1;i<=n;i++){
        int r1 = p1.root(i);
        int r2 = p2.root(i);
        dp[mp(r1, r2)]++;
    }
    for(int i=1;i<=n;i++){
        int r1 = p1.root(i);
        int r2 = p2.root(i);
        printf("%lld ", dp[mp(r1, r2)]);
    }
}