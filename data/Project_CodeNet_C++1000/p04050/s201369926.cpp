#include <cstdio>

#define MAXN 100009

int ans[MAXN+1], par[MAXN+1], impar[MAXN+1];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i=1; i<=m; i++){
        int x;
        scanf("%d", &x);

        if(x%2) impar[++impar[0]]=x;
        else par[++par[0]]=x;
    }

    if(impar[0]>2) printf("Impossible\n");
    else{
        int tr=0;
        if(impar[0]>0){
            if(impar[1]>1)
                ans[++ans[0]]=impar[1]-1;
            tr=1;
        }

        for(int i=1; i<=par[0]; i++){
            if(tr==0){
                ans[++ans[0]]=par[i]-1;
                tr=1;
            }else ans[++ans[0]]=par[i];
        }

        if(impar[0]>1) ans[++ans[0]]=impar[2]+1;
        else ans[++ans[0]]=1;

        if(impar[0]>0) printf("%d ", impar[1]);
        for(int i=1; i<=par[0]; i++)
            printf("%d ", par[i]);
        if(impar[0]>1) printf("%d ", impar[2]);
        printf("\n%d\n", ans[0]);
        for(int i=1; i<=ans[0]; i++)
            printf("%d ", ans[i]);
    }

    return 0;
}
