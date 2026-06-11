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
using namespace std;


int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> t(n), a(n);

    int max=0;
    int max_left=0, max_right=-1;
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &t[i]);
        if(max<t[i]) {
            max=t[i]; max_left=i;
        }
    }
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
        if(max==a[i]) max_right=i;
    }
    if(max_right<0 || max_left>max_right) {
        printf("0\n"); return 0;
    }

    ll ans=1;
    for(i=1; i<max_left; i++) {
        if(t[i-1]==t[i]) {
            ans = ans * t[i] %MOD;
        }
    }
    for(i=max_left+1; i<max_right; i++) {
        if(t[i]!=max) {
            printf("0\n"); return 0;
        }
        ans = ans * max %MOD;
    }
    for(i=max_right+1; i<n-1; i++) {
        if(a[i]==a[i+1]) {
            ans = ans * a[i] %MOD;
        }
    }
    printf("%lld\n", ans);

    return 0;
}
