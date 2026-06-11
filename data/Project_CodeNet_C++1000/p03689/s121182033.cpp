#include<stdio.h>
#include <stdlib.h>
#include<string>
#include<queue>
#include<algorithm>
#include<math.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
const long long INF = 1LL << 60;

int main(){
    int H, W, h, w;
    scanf("%d %d %d %d", &H, &W, &h, &w);
    if(h*w == 1){
        printf("No\n");
        return 0;
    }
    long long plus = 999999999/(h*w - 1);
    long long minus = -plus*(h*w - 1) - 1;
    if(plus*(H*W - (H/h*h)*(W/w*w)) - (H/h)*(W/w) < 0) printf("No\n");
    else{
        printf("Yes\n");
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if(j) printf(" ");
                printf("%lld", ((i + 1) % h == 0 && (j + 1) % w == 0) ? minus : plus);
                if(j == W - 1) printf("\n");
            }
        }
    }
    return 0;
}