#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int maxn=500010,inf=1e9;
int n;
int pos[maxn][26],f[maxn];
char s[maxn];
void read(int &k)
{
    int f=1;k=0;char c=getchar();
    while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
    while(c<='9'&&c>='0')k=k*10+c-'0',c=getchar();
    k*=f;
}
int main()
{
    scanf("%s",s+1);n=strlen(s+1);
    memset(f,32,(n+1)<<2);f[n+1]=1;f[n+2]=0;
    for(int i=0;i<26;i++)pos[n+1][i]=n+1;
    for(int i=n;i;i--)
    {
        for(int j=0;j<26;j++)
        pos[i][j]=pos[i+1][j];
        pos[i][s[i]-'a']=i;
    }
    for(int i=n;i;i--)
    for(int j=0;j<26;j++)
    f[i]=min(f[i],f[pos[i][j]+1]+1);
    int now=1;
    for(int j=f[1];j;j--)
    for(int i=0;i<26;i++)
    if(f[now]==f[pos[now][i]+1]+1)
    {
        putchar(i+'a');
        now=pos[now][i]+1;
        break;
    }
}