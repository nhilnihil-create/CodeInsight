#include<cstdio>
int n, ans;
int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        int a;scanf("%d",&a);
        ans += a;ans %= 2;
    }
    if(ans == 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}