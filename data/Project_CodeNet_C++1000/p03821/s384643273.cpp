#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100005;
int n,a[maxn],b[maxn];
ll ans;
inline int read(){
    int res=0,f_f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f_f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)-'0'+ch,ch=getchar();
    return res*f_f;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        a[i]=read(),b[i]=read();
    }
    for (int i=n;i;i--){
        a[i]=(ans+a[i])%b[i];
        if(a[i]) ans+=b[i]-a[i];
    }
    printf("%lld\n",ans);
    return 0;
}