#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char s[MN+5];
int n,nxt[MN+5][26],f[MN+5];
int main()
{
    scanf("%s",s+1);n=strlen(s+1);for(int i=0;i<26;++i)nxt[n+1][i]=n+1;
    for(int i=n;i;--i) memcpy(nxt[i],nxt[i+1],sizeof(nxt[0])),nxt[i][s[i]-'a']=i;
    for(int i=n;~i;--i)
    {
        f[i]=1e9;
        for(int j=0;j<26;++j) f[i]=min(f[i],f[nxt[i+1][j]]+1);
    }
    for(int i=0;i<=n;)
        for(int j=0;j<26;++j) if(f[nxt[i+1][j]]==f[i]-1)
        {
            printf("%c",j+'a');i=nxt[i+1][j];
            break;
        }
    return 0;
}
