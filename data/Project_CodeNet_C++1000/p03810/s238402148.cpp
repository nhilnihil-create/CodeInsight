#include<cstdio>
int n, w[101000];
long long sum;
int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}
void Print(int ck){
    if(!ck)printf("First\n");
    else printf("Second\n");
}
int main(){
    int i, pv = 0, ck = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    while(1){
        int c = 0;
        sum = 0;
        for(i=1;i<=n;i++){
            sum += w[i];
            if(w[i]&1)c++,pv=i;
        }
        if(sum%2!=n%2){
            Print(ck);
            return 0;
        }
        if(c!=1 || w[pv] == 1){
            Print(!ck);
            return 0;
        }
        w[pv]--;
        int g = 0;
        for(i=1;i<=n;i++)g = gcd(g,w[i]);
        for(i=1;i<=n;i++)w[i]/=g;
        ck = !ck;
    }
}