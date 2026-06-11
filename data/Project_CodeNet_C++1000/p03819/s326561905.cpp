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

int ft[100005];
void update(int i, int v){
    for(;i<=100000;i+=(i&-i)) ft[i] += v;
}
int query(int i){
    int ans = 0;
    for(;i>0;i-=(i&-i)) ans+=ft[i];
    return ans;
}

int l[300005], r[300005];
vector<int> del[100005];
int main(){
    int n, m, sum = 0;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d%d", &l[i], &r[i]);
        del[r[i]-l[i]+1].emplace_back(i);
        sum++;
    }

    for(int d=1;d<=m;d++){
        int ans = sum;
        for(int i=d;i<=m;i+=d){
            ans += query(i);
        }

        for(int j=0;j<sz(del[d]);j++){
            int idx = del[d][j];
            update(l[idx], 1);
            update(r[idx]+1, -1);
            sum--;
        }
        printf("%d\n", ans);
    }
}