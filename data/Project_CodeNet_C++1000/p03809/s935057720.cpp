#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#include <time.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
 
using namespace std;

vector<ll> a;
vector<vector<int> > g;  // to

bool dfs(int par, int curr, ll& ans)
{
    int siz=(int)g[curr].size();
    int i;
    ll sum=0;
    int cnt=0;
    ll max=0;
    for(i=0; i<siz; i++) {
        int next=g[curr][i];
        if(par==next) continue;

        cnt++;
        ll ret=0;
        if(!dfs(curr, next, ret)) {
            return false;
        }
        max=MAX(max,ret);
        sum+=ret;
    }
    if(cnt==0) {
        ans=a[curr];
    }
    else if(curr==0 && cnt==1) {
        ans=a[curr]-sum;
    }
    else {
        ans=a[curr]*2-sum;
        max=MAX(max,ans);
        if(max>a[curr]) {
            return false;
        }
    }
    if(ans<0) {
        return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    a.resize(n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }
    g.resize(n);
    for(i=0; i<n-1; i++) {
        int p,q;
        scanf("%d%d", &p, &q); p--; q--;
        g[p].push_back(q);
        g[q].push_back(p);
    }
    ll ret=0;
    bool ok=dfs(-1,0,ret);
    if(!ok || ret!=0) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
    }

    return 0;
}
