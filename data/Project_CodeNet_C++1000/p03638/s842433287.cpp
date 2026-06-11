#include <stdio.h>
int main(void){
    int h,w,n,i,j,count=1,color=1;
    scanf ("%d %d %d",&h,&w,&n);
    int a[n+1],c[h][w];
    //printf("h=%d,w=%d,n=%d\n",h,w,n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        //printf("color=%dが%d\n",i,a[i]);
    };
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            c[i][i%2==0?j:w-j-1]=color;
            //printf("上から%d,左から%dが%d\n",i,i%2==0?j:w-j-1,color);
            //牛耕法
            count++;
            if(a[color]<count){
                count=1;
                color++;
            };
        };
    };
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            printf("%d ",c[i][j]);
        };
        printf("\n");
    };
    return 0;
};
