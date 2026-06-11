#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define Rep(x,y) for(int x = 0; x < y; x++)
#define Repe(x,y,z) for(int x = z; x < y; x++)

int main() {

    bool cnt = false;
    int n;
    int a;
    int ans = 0;
    scanf("%d", &n);
    Repe(i,n+1,1){
        scanf("%d", &a);
        if( a == i ){
            if( cnt ) {
                ans++; cnt = false;
            }else{
                cnt = true;
            }
        }else{
            if( cnt ){
                ans++; cnt = false;
            }
        }
    }

    if( cnt ) ans++;

    printf ("%d\n", ans);
    return 0;
}

