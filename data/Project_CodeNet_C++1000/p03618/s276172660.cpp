#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
char str[MAXN];
int alp[27];
long long ans;
int main()
{
    scanf("%s",str+1);
    int n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=25;j++)
        {
            if(j==(str[i]-'a'))
            {
                continue;
            }
            else
            {
                ans+=alp[j];
            }
        }
        alp[str[i]-'a']++;
    }
    printf("%lld\n",ans+1);
}