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

char str0[100005];
char str1[100005];

int main(int argc, char* argv[])
{
    scanf("%s%s", str0, str1);
    
    int len0=strlen(str0);
    int len1=strlen(str1);
    vector<int> s0(len0+1), s1(len1+1);
    int i;
    for(i=0; i<len0; i++) {
        if(str0[i]=='B') s0[i+1]=s0[i]+2;
        else s0[i+1]=s0[i]+1;
    }
    for(i=0; i<len1; i++) {
        if(str1[i]=='B') s1[i+1]=s1[i]+2;
        else s1[i+1]=s1[i]+1;
    }

    int T;
    scanf("%d", &T);
    int t;
    for(t=0; t<T; t++) {
        int a,b,c,d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int ans=(s0[b]-s0[a-1]-s1[d]+s1[c-1]+6)%3;
        if(ans==0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}
