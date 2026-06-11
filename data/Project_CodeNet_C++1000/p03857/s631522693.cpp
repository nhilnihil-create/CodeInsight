#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

int ro[200005], ra[200005], n, k, l;

int Find(int *r, int x) {
    return r[x]==x ? x : r[x]=Find(r, r[x]);
}

void init() {
    for(int i=1;i<=n;i++) {
        ra[i]=ro[i]=i;
    }
}

vector <int> ve[200005];
map <int, int> ma;
int ans[200005];

int main () {
    int u, v;
    scanf("%d%d%d", &n, &k, &l);
    init();
    for(int i=1;i<=k;i++) {
        scanf("%d%d", &u, &v);
        u=Find(ro, u), v=Find(ro, v);
        if(u!=v) {
            ro[u]=v;
        }
    }

    for(int i=1;i<=l;i++) {
        scanf("%d%d", &u, &v);
        u=Find(ra, u), v=Find(ra, v);
        if(u!=v) {
            ra[u]=v;
        }
    }

    for(int i=1;i<=n;i++) {
        ve[Find(ro, i)].push_back(i);
    }

    for(int i=1;i<=n;i++) {
        ma.clear();
        for(int j=0;j<(int)ve[i].size();j++) {
            ma[Find(ra, ve[i][j])]++;
        }

        for(int j=0;j<(int)ve[i].size();j++) {
            ans[ve[i][j]]+=ma[Find(ra, ve[i][j])];
        }
    }

    for(int i=1;i<=n;i++) {
        printf("%d%c", ans[i], i==n ? '\n' : ' ');
    }
    return 0;
}