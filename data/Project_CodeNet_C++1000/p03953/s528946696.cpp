#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m; ll k;
ll arr[100100];
ll perm[100100];
ll ans[100100];

int main() {
    int i, j;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld",&arr[i]);
    for (i=0;i<n;i++) perm[i] = i;
    scanf("%d%lld",&m,&k);
    for (i=0;i<m;i++) {
        int a;
        scanf("%d",&a);
        swap(perm[a-2],perm[a-1]);
    }
    for (i=0;i<n-1;i++) {
        if (perm[i]<0) continue;
        vector<ll> vec;
        int p = i;
        do {
            vec.push_back(p);
            p = perm[p];
        } while(p!=i);
        for (j=0;j<vec.size();j++) {
            ans[vec[j]] = vec[(j+k)%vec.size()];
            perm[vec[j]] = -1;
        }
    }
    printf("%lld\n",arr[0]);
    ll s = arr[0];
    for (i=0;i<n-1;i++) {
        s += arr[ans[i]+1]-arr[ans[i]];
        printf("%lld\n",s);
    }

    return 0;
}
