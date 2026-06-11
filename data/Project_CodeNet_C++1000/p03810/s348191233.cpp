#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100010],even,odd;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if (a[i]&1) odd++;else even++;
    }
    if (even&1) return puts("First"),0;else
    if (odd>1) return puts("Second"),0;
    int cnt=0;
    while (1){
        int p=0;
        for (int i=1;i<=n;i++)
        if (a[i]&1) if (p) goto end;else p=i;
        if (a[p]==1) break;
        a[p]--;cnt++;
        int Gcd=0;
        for (int i=1;i<=n;i++) Gcd=gcd(Gcd,a[i]);
        for (int i=1;i<=n;i++) a[i]/=Gcd;
    }
    end:
    even=0;
    for (int i=1;i<=n;i++) even+=((a[i]&1)^1);
    puts((even+cnt)&1?"First":"Second");
    return 0;
}