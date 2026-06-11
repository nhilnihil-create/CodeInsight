#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=1e5+10;
int n,k,sum=0,count[N],q[N],h=1,t=0,fa[N],ll[N];
int read(){
    int f=1,ans=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-48;c=getchar();}
    return ans*f;
}
int main(){
    n=read();k=read();
    int a=read();if(a!=1)sum++;
    for(int i=2;i<=n;i++){
        a=read();fa[i]=a;count[a]++;
    }
    for(int i=2;i<=n;i++)if(!count[i])q[++t]=i;
    while(h<=t){
        int x=q[h];h++;
        if(x==1)break;
        if(fa[x]!=1&&ll[x]==k-1)sum++;
        else ll[fa[x]]=std::max(ll[fa[x]],ll[x]+1);
        count[fa[x]]--;
        if(!count[fa[x]])q[++t]=fa[x];
    }
    printf("%d\n",sum);
    return 0;
}
