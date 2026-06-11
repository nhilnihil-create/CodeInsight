#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>>
using namespace std;
#define maxn 105
int mp[maxn][maxn];
int a[maxn*maxn];

int main(){
    int H,W,N;
    scanf("%d%d",&H,&W);
    getchar();
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);
    int index = 1;
    for(int i=1;i<=H;i++){
        if(i%2){
            for(int j=1;j<=W;j++){
                if(a[index]==0){
                    index ++;
                    mp[i][j] = index;
                    a[index] --;
                }
                else if(a[index] > 0){
                    mp[i][j] = index;
                    a[index] --;
                }
            }
        }
        else {
            for(int j=W;j>=1;j--){
                if(a[index]==0){
                    index ++;
                    mp[i][j] = index;
                    a[index] --;
                }
                else if(a[index] > 0){
                    mp[i][j] = index;
                    a[index] --;
                }
            }
        }
    }
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            printf("%d ",mp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
