#include<cstdio>
int f[505][505];

int main(){
    /*int n;
    scanf("%d",&n);
    for(int s = 0; s <= n; s++){
        for(int i = 0; i <= s; i++){
            int j = s-i;
            if(i<=1 && j<=1) f[i][j] = 0;
            else{
                for(int take = 2; take <= i; take += 2){
                    int li = i-take, lj = j+take/2;
                    if(f[li][lj]==0) f[i][j] = 1;
                }
                for(int take = 2; take <= j; take += 2){
                    int li = i+take/2, lj = j-take;
                    if(f[li][lj]==0) f[i][j] = 1;
                }
            }
            //printf("f[%d][%d] = %d\n",i,j,f[i][j]);
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = i; j <= n-i; j++){
            printf("f[%d][%d] = %d\n",i,j,f[i][j]);
        }
    }*/
    long long x,y;
    scanf("%lld%lld",&x,&y);
    if(x>y){
        long long t = x;
        x = y;
        y = t;
    }
    if(x==y || (x+1)==y) printf("Brown\n");
    else printf("Alice\n");
    return 0;
}
