#include <bits/stdc++.h>
using namespace std;
const int maxn=112345;
int n,m,x[maxn];
long long K;
vector<int> perm;
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",&x[i]);
    scanf("%d%lld",&m,&K);
    for (int i=0;i<n-1;++i) perm.push_back(i);
    for (int i=0;i<m;++i) {
        int t;scanf("%d",&t);
        swap(perm[t-1],perm[t-2]);
    }
    vector<int> ret(n-1);
    for (int i=0;i<n-1;++i) ret[i]=i;
    while (K) {
        if (K&1) {
            vector<int> nxt(n-1);
            for (int i=0;i<n-1;++i)
                nxt[i]=ret[perm[i]];
            for (int i=0;i<n-1;++i)
                ret[i]=nxt[i];
        }
        K>>=1;
        vector<int> nxt(n-1);
        for (int i=0;i<n-1;++i)
            nxt[i]=perm[perm[i]];
        for (int i=0;i<n-1;++i)
            perm[i]=nxt[i];
    }
    for (int i=0;i<n-1;++i) perm[i]=ret[i];
    long long now=x[0];
    printf("%lld\n",now);
    for (int i=0;i<n-1;++i) {
        now+=x[perm[i]+1]-x[perm[i]];
        printf("%lld\n",now);
    }
    return 0;
}
