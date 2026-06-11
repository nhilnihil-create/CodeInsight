#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[105];
int cnt[100];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            cnt[s[j]-'a'+1]++;
        }
    }
    if(n%2==0&&m%2==0)
    {
        for(int j=1;j<=26;j++)
        {
            if(cnt[j]%4!=0)
            {
                puts("No");
                return 0;
            }
        }
        puts("Yes");
        return 0;
    }
    else if(n%2==1&&m%2==1)
    {
        int tmp=0,tt=0;
        for(int i=1;i<=26;i++)
        {
            if(cnt[i]%2==1)tt++;
            tmp+=cnt[i]/4;
        }
        if(tt>1||tmp<(n-1)*(m-1)/4)puts("No");
        else puts("Yes");
    }
    else
    {
        if(n%2==0)swap(n,m);
        int tmp=0;
        for(int i=1;i<=26;i++)
        {
            if(cnt[i]%2==1)
            {
                puts("No");
                return 0;
            }
            else tmp+=cnt[i]/4;
        }
        if(tmp<(n-1)*m/4)puts("No");
        else puts("Yes");
    }
    return 0;
}