#include<bits/stdc++.h>
using namespace std;
long long arr[100005];
vector<long long>v,rs;
main()
{
	int m,n;
    long long re;
    scanf("%d%d",&m,&n);
    for(int i = 0;i < m;i++)
    {
        scanf("%lld",&re);
        rs.push_back(re);
    }
    long long sm=0;
    for(int i = 0;i < n;i++)
    {
        scanf("%lld",&re);
        v.push_back(re);
        if(i>0)
        arr[i]=v[i]-v[i-1];
        arr[i]*=(n-i);
        arr[i]%=1000000007;
        arr[i]*=(i);
        arr[i]%=1000000007;
        sm+=arr[i];
        sm%=1000000007;
    }
    // printf("-->%lld\n",sm);
    long long cal=0;
    for(int i = 1;i < m;i++)
    {
        long long pls=sm*i;
        // printf("%d\n",sm*(n-i)*i);
        pls%=1000000007;
        pls*=(m-i);
        pls%=1000000007;
        pls*=(rs[i]-rs[i-1]);
        pls%=1000000007;
        cal+=pls;
        cal%=1000000007;
    }
    printf("%lld",cal);
}
