#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005

int main(){
    int hh,ww,h,w;
    scanf("%d %d %d %d",&hh,&ww,&h,&w);
    if(hh%h==0&&ww%w==0){
        printf("No\n");
    }
    else{
        printf("Yes\n");
        for(int i = 0;i<hh;i++){
            for(int j=0;j<ww;j++){
                if(i%h==0&&j%w==0){
                    printf("999999999 ");
                }
                else if(i%h==h-1&&j%w==w-1){
                    printf("-1000000000 ");
                }
                else{
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/