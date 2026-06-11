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
//const long long MOD = 1000000007;
const long long MOD = 998244353;
using namespace std;

char str[200005];

int main(int argc, char* argv[])
{
    scanf("%s", str);
    int n=strlen(str);
    int cnt[26]={0};
    int i;
    ll ans=0;
    for(i=0; i<n; i++) {
        int tmp=str[i]-'a';
        ans+=(i-cnt[tmp]);
        cnt[tmp]++;
    }
    printf("%lld\n", ans+1);

    return 0;
}
