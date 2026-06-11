#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>mp,mp2;
int a[100005],b[100005];
long long arr[15];
main()
{
	int m,n,t;
    scanf("%d%d%d",&m,&n,&t);
    for(int i = 0;i < t;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        mp[make_pair(a[i],b[i])]=1;
    }
    for(int i = 0;i < t;i++)
    {
        for(int j = max(a[i]-1,2);j <= min(a[i]+1,m-1);j++)
        {
            for(int k = max(b[i]-1,2);k <= min(b[i]+1,n-1);k++)
            {
                if(mp2[make_pair(j,k)]==1)
                continue;
                int cs=0;
                for(int l = j-1;l <= j+1;l++)
                {
                    for(int mm = k-1;mm <= k+1;mm++)
                    {
                        if(mp.find(make_pair(l,mm))!=mp.end())
                        cs++;
                    }
                }
                arr[cs]++;
                mp2[make_pair(j,k)]=1;
            }
        }
    }
    long long cal=m-2;
    cal*=n-2;

    for(int i = 1;i <= 9;i++)
    cal-=arr[i];
    arr[0]=cal;
    for(int i = 0;i <= 9;i++)
    printf("%lld\n",arr[i]);
}
