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
    int n,T;
    scanf("%d%d", &n, &T);
    map<int,int> z;
    int i;
    int maxval=0;
    ll  maxcnt=0;
    for(i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if(!z.empty()) {
            auto it=z.begin();
            int tmp0=it->first;
            int val=tmp-tmp0;
            if(val>maxval) {
                maxval=val;
                maxcnt=it->second;
            }
            else if(val==maxval) {
                maxcnt+=it->second;
            }
        }
        z[tmp]++;
    }
    printf("%lld\n", maxcnt);

    return 0;
}
