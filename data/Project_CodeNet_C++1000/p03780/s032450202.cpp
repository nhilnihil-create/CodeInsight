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
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223372036854775807
#define INF 2147483647
#define MOD 1000000007
using namespace std;

int main(int argc, char* argv[])
{
    long n,k;
    scanf("%ld%ld", &n, &k);

    vector<long> a(n);
    long i;
    for(i=0; i<n; i++) {
        scanf("%ld", &a[i]);
    }
    sort(a.begin(), a.end());

    vector<long> s(n+1);
    s[0]=0;
    for(i=0; i<n; i++) {
        s[i+1]=s[i]+a[i];
    }

    long ans=0;
    long ll=-1, rr=n;
    while( rr-ll>1 ) {
        long curr = (ll+rr)/2;

        vector<long> vis(k,0);

        vis[0]=1;
        if(0>=k-a[curr]) {
            rr=curr;  // curr is needed
            continue;
        }

        long j;
        for(i=0; i<n; i++) {
            if(i==curr) continue;
            for(j=k-1; j>=0; j--) {
                if(vis[j]==0 && j>=a[i] && vis[j-a[i]]) {
                    vis[j]=1;
                    if(j>=k-a[curr]) {
                        break;
                    }
                }
            }
            if(j>=0) {
                break;
            }
        }

        if(i==n) {
            ll=curr;  // curr is no need
        }
        else {
            rr=curr;  // curr is needed
        }
    }

    printf("%ld\n", ll+1);

    return 0;
}

