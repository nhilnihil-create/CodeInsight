#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
typedef short int sh;

const int inf=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=1e9+7;

int b=101,t=-101,ans=inf;
int a[MAX];

void Fun(int k,int n)
{
    int temp=0;
    for(int i=0;i<n;i++)
    {
        temp+=(a[i]-k)*(a[i]-k);
    }
    ans=min(ans,temp);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        b=101;   t=-101;
        ans=inf;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            t=max(t,a[i]);
            b=min(b,a[i]);
        }
        for(int i=b;i<=t;i++)
        {
            Fun(i,n);
        }
        cout<<ans<<endl;
    }
    return 0;
}
