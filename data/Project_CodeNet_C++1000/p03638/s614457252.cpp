#include <bits/stdc++.h>
using namespace std;

int h,w;
int n;
int a[100005];
int MAP[105][105];

int main(){
    scanf("%d%d",&h,&w);
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    int Pos = 1;
    for(int i = 1; i <= h; i++){
        if(i % 2 == 1){
            for(int j = 1; j <= w; j++){
                if(a[Pos] > 0){
                    a[Pos]--;
                    MAP[i][j] = Pos;
                }
                else{
                    Pos++;
                    a[Pos]--;
                    MAP[i][j] = Pos;
                }
            }
        }
        else{
            for(int j = w; j >= 1; j--){
                if(a[Pos] > 0){
                    a[Pos]--;
                    MAP[i][j] = Pos;
                }
                else{
                    Pos++;
                    a[Pos]--;
                    MAP[i][j] = Pos;
                }
            }
        }
    }
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            printf("%d ",MAP[i][j]);
        }
        printf("\n");
    }
    return 0;

}
