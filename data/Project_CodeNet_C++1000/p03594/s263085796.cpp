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
    int h,w,d;
    scanf("%d%d%d", &h, &w, &d);

    char str[]="RYGB";
    if(d%2==1) {
        int i,j;
        for(i=0; i<h; i++) {
            for(j=0; j<w; j++) {
                printf("%c", str[(i+j)%2]);
            }
            printf("\n");
        }
    }
    else {
        int d0=d/2;
        int i,j;
        for(i=0; i<h; i++) {
            for(j=0; j<w; j++) {
                int tmp0=(i+j)/d;
                int tmp1=((i%(d*2))-(j%(d*2))+(d*2))%(d*2)/d;

                printf("%c", str[(tmp0%2)+(tmp1%2)*2]);
            }
            printf("\n");
        }
    }


    return 0;
}
