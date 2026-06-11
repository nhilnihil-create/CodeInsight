#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=100005;
int n,a[maxn];
ll sum[maxn];
template<class Type>Type read(){
    Type res=0,f_f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f_f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)-'0'+ch,ch=getchar();
    return res*f_f;
}
#define iread() (read<int>())
#define lread() (read<long long>())
#define ulread() (read<unsigned long long>())
int main(){
    n=iread();
    for (int i=1;i<=n;i++){
        a[i]=iread();
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int now=n;
    for (int i=n-1;i;i--){
        if((sum[i]<<1)<a[i+1]) break;
        now=i;
    }
    printf("%d\n",n-now+1);
    return 0;
}