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

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    int i;
    vector<int> a(n);
    ll sum=0;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
        sum+=(a[i]+1)%2;
    }
    int flag=0;
    while(sum==n-1 && n%2) {
        int tmp=0;
        for(i=0; i<n; i++) {
            if(a[i]%2) {
                if(a[i]==1) break;
                a[i]--;
            }
            if(i==0) tmp=a[i];
            else tmp=gcd(tmp,a[i]);
        }
        if(i==n) {
            sum=0;
            for(i=0; i<n; i++) {
                a[i]/=tmp;
                if(a[i]%2==0) sum++;
            }
            flag=1-flag;
            continue;
        }
        break;
    }

    if((sum+flag)%2) {
        printf("First\n");
    }
    else {
        printf("Second\n");
    }

    return 0;
}
