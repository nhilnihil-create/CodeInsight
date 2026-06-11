#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=100005;
int n,C,K,a[maxn],ans;
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
    n=iread(),C=iread(),K=iread();
    for (int i=1;i<=n;i++){
        a[i]=iread();
    }
    sort(a+1,a+n+1);
    int t=0;
    for (int i=1,j=1;i<=n;i=j+1){
        t=a[i]+K,ans++;
        while(j<=n&&a[j+1]<=t&&j-i+1<C) j++;
    }
    printf("%d\n",ans);
    return 0;
}