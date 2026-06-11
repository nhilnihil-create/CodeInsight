#include<stdio.h>
int n, w[101000], pv;
long long S[101000], MM, SS;
char op[101000];
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        S[i] = S[i-1] + w[i];
        if(i==n)break;
        scanf("%s",op+i);
    }
    for(i=1;i<=n;i++)if(op[i]=='-')MM += w[i+1];
    for(i=1;i<=n;i++){
        if(op[i]=='-'){
            if(!pv){
                pv = i;
                continue;
            }
            if(MM > S[i] - S[pv] + SS)MM = S[i] - S[pv] + SS;
            SS += w[pv+1];
            pv = i;
        }
    }
    printf("%lld\n",S[n] - MM*2);
}