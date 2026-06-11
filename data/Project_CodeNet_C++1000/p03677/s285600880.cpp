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
#pragma warning(disable:4996) 

typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;



void solve()
{
    int n,m;
    scanf("%d%d", &n, &m);

    vector<int> a(n);
    vector<vector<int> > z(m);
    int i;
    ll sum=0;
    int cnt=0;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]); a[i]--;
        if(i>0) {
            if(a[i-1]>a[i]) {
                sum+=1+a[i];
                cnt++;
            }
            else {
                sum+=a[i]-a[i-1];
            }
        }
        z[a[i]].push_back(i);
    }

    ll ans=sum;
#ifdef _DEBUG
    printf("%lld, %d\n", sum, cnt);
#endif
    int j;
    for(i=0; i<m-1; i++) {
        ll diff=0;
        for(j=0; j<(int)z[i].size(); j++) {
            int k=z[i][j];
            if(k>0) {
                int tmp=(a[k]-a[k-1]+m)%m;
                diff+=(tmp-1);
            }
            else {
                cnt++;
            }
            if(k==n-1) {
                cnt--;
            }
            else {
                diff++;
            }
        }
        diff-=cnt;
        sum+=diff;
#ifdef _DEBUG
        printf("%lld\n", sum);
#endif
        ans=MIN(ans,sum);
    }
    printf("%lld\n", ans);
    

    return;
}


int main(int argc, char* argv[])
{
#if 1
	solve();
#else
	int T; scanf("%d", &T);
	while (T--) {
		solve();
	}
#endif
	return 0;
}
