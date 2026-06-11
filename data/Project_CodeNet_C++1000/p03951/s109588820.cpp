#include<bits/stdc++.h>
using namespace std;
const int N=110;
char s[N],t[N];
int main()
{
    int n,ans=0;
    scanf("%d%s%s",&n,s+1,t+1);
    for(int i=1;i<=n;i++)
    {
        int f=1;
        for(int j=1;j<=i;j++)if(s[n-i+j]!=t[j]){f=0;break;}
        if(f)ans=max(ans,i);
    }
    printf("%d\n",2*n-ans);
}
