#include<cstdio>
int a[100005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    int p = 1, ans = 0;
    while(p<=n){
        if(a[p]!=p) p++;
        else{
            int np = p;
            while(np+1<=n && a[np+1]==np+1) np++;
            int len = np-p+1;
            ans += len/2+len%2;
            p = np+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
