#include<cstdio>
#include<algorithm>
using namespace std;
int W,H,w,h,sum,ans[510][510],v;
int main(){
    scanf("%d%d%d%d",&H,&W,&h,&w);
    if(H%h==0&&W%w==0){puts("No");return 0;}
    v=500*500/(w*h-1);
    for(int i=1;i<=H;i++)
        for(int j=1;j<=W;j++){
            if(i%h==0&&j%w==0)ans[i][j]=-(w*h-1)*v-1;
            else ans[i][j]=v;
            sum+=ans[i][j];
        }
    if(sum>0){
        puts("Yes");
        for(int i=1;i<=H;i++,puts(""))
            for(int j=1;j<=W;j++)
                printf("%d ",ans[i][j]);
    }
    else puts("No");
}
