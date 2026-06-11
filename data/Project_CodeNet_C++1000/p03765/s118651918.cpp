#include <cstdio>
#include <cstring>

int q,a,b,c,d,s1[100005],s2[100005];
char s[100005],t[100005];

int Calc(int *S,int l,int r){return S[r]-S[l-1];}

int main()
{
    scanf("%s%s%d",s+1,t+1,&q);
    int sl=strlen(s+1),tl=strlen(t+1);
    for(int i=1;i<=sl;++i)s1[i]=s1[i-1]+(s[i]=='A');
    for(int i=1;i<=tl;++i)s2[i]=s2[i-1]+(t[i]=='A');
    while(q--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int c1=(b-a+1+Calc(s1,a,b))%3;
        int c2=(d-c+1+Calc(s2,c,d))%3;
        puts(c1==c2?"YES":"NO");
    }
    return 0;
}