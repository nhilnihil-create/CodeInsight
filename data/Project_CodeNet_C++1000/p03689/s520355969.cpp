#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define prin(num) cout << num << endl
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 1000005
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PA;
typedef priority_queue<ll> PQ;
typedef map<ll, ll> Map;

int main(void) {
    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    ll i, j;
    
    if(H%h==0 && W%w==0) {
        puts("No");
        return 0;
    }
    
    
    ll bigcnt=(H/h)*(W/w);
    ll smallcnt=H*W-bigcnt;
    ll par=1000000000/smallcnt;
    ll bignum=-smallcnt*par+1;
    ll smallnum=bigcnt*par;
    
    puts("Yes");
    for(i=0; i<H; i++) {
        for(j=0; j<W; j++) {
            if(i%h==h-1 && j%w==w-1) {
                printf("%lld ", bignum);
            }else {
                printf("%lld ", smallnum);
            }
        }
        printf("\n");
    }

}