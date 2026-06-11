#include<bits/stdc++.h>
using namespace std;
int read()
{
    char s;
    int k=0,base=1;
    while((s=getchar())!='-'&&s!=EOF&&!(s>='0'&&s<='9'));
    if(s==EOF)exit(0);
    if(s=='-')base=-1,s=getchar();
    while(s>='0'&&s<='9')
    {
        k=k*10+(s-'0');
        s=getchar();
    }
    return k*base;
}
void write(int x)
{
    if(x<0)
    {
        putchar('-');
        write(-x);
    }
    else
    {
        if(x/10)write(x/10);
        putchar(x%10+'0');
    }
}
long long n,ans;
const long long mod=1e9+7;
long long g[1000010];
long long s[1000010];
int main()
{
    n=read();
    g[1]=n;g[2]=n*n;
	s[1]=n;s[2]=n*n+n;
    for (long long i=3;i<=n;i++)
    {
        g[i]=g[i-1];
        /*for (int j=3;j<=n+1;j++)
        {
            if (i-j<=0) 
			{
				g[i]+=n; 
				if (g[i]>=mod) g[i]-=mod;
			}
			else
			{
           		g[i]+=g[i-j]; 
				g[i]+=(n-1);
				if (g[i]>=mod) g[i]-=mod;
			}
        }*/
		g[i]+=s[i-3];
		g[i]+=((long long)(i-3)*(long long)(n-1)%(long long)mod);
		g[i]=(g[i]%mod+mod)%mod;
		if (g[i]>=mod) g[i]%=mod;
//		printf("%d ",g[i]);
		g[i]+=(long long)(n+2-i)*(long long)(n)%(long long)mod;
		g[i]%=mod;
		s[i]=s[i-1]+g[i];if (s[i]>=mod) s[i]-=mod;
//		printf("%d \n",g[i]);
    }
    printf("%lld\n",g[n]);
    return 0;
}
/*
 1. 数组仅包含 1, 2, 3, ..., n
2. 如果 n ≤ i, j,那么 a i = a j
3. 如果 i < j < k ≤ i + a i ,那么 a j = a k
数组还在生成中,反正现在很无聊,不如计算有多少种满足条件的数组?答案对 1e9 + 7 取模
 */
