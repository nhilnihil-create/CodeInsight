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


int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> x(n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &x[i]);
    }
    int L,Q;
    scanf("%d%d", &L, &Q);
    
    vector<vector<int> > ne(n), pr(n);
    int j;
    for(i=0; i<n; i++) {
        ne[i].resize(20); pr[i].resize(20);
        for(j=0; j<20; j++) {
            ne[i][j]=INF; pr[i][j]=-INF;
        }
    }
    for(i=0; i<n; i++) {
        int k=lower_bound(x.begin(), x.end(), x[i]+L+1)-x.begin()-1;
        ne[i][0]=k;

        k=lower_bound(x.begin(), x.end(), x[i]-L)-x.begin();
        pr[i][0]=k;
    }
    for(j=1; j<20; j++) {
        for(i=0; i<n; i++) {
            if(ne[i][j-1]<INF) {
                ne[i][j]=ne[ne[i][j-1]][j-1];
            }
            if(pr[i][j-1]>-INF) {
                pr[i][j]=pr[pr[i][j-1]][j-1];
            }
        }
    }

    for(i=0; i<Q; i++) {
        int a,b;
        scanf("%d%d", &a, &b); a--; b--;

        if(b>a) {
            int curr=a;
            int ans=0;
            for(j=19; j>=0; j--) {
                if(ne[curr][j]<b) {
                    ans+=(1<<j);
                    curr=ne[curr][j];
                }        
            }
            printf("%d\n", ans+1);
        }
        else {
            int curr=a;
            int ans=0;
            for(j=19; j>=0; j--) {
                if(pr[curr][j]>b) {
                    ans+=(1<<j);
                    curr=pr[curr][j];
                }        
            }
            printf("%d\n", ans+1);
        }

    }


    return 0;
}