
#include<cstdio>
int n, m, d;
char p[5]="RGBY";
int main(){
    int i, j;
    scanf("%d%d%d",&n,&m,&d);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int c = ((i+j)%(2*d))/d*2 + ((i-j+m)%(2*d))/d;
            printf("%c",p[c]);
        }
        printf("\n");
    }
}