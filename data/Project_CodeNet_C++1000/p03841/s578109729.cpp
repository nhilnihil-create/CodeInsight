#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=3e5+10;
typedef pair<int,int> pii;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int n,ans[N],rem[N];
pii a[N];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) a[i].fi=gi(),a[i].se=i;
    sort(a+1,a+n+1);
    int p=1;
    for(int i=1;i<=n;i++) {
        ans[a[i].fi]=a[i].se;
        for(int j=1;j<=a[i].se-1;j++) {
            while(ans[p]) p++;
            ans[p]=a[i].se; p++;
        }
        if(p-1>a[i].fi) return puts("No"),0;
    }
    for(int i=1;i<=n;i++) rem[i]=n-i;
    for(int i=p,j=1;i<=n*n;i++) {
        if(ans[i]) continue;
        while(!rem[a[j].se]) j++;
        if(a[j].fi>i) return puts("No"),0;
        ans[i]=a[j].se;rem[a[j].se]--;
    }
    puts("Yes");
    for(int i=1;i<=n*n;i++) printf("%d ",ans[i]);
    return 0;
}
//orzgzy
//鸡贼明年进队超稳
