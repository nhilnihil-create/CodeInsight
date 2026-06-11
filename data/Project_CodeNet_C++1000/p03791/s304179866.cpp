#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <stack>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int a[100500];

void init()
{

    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    int MOD=1e9+7;
    long long ans;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int s,k;
    s=1;k=1;ans=1;
    for (int i=1;i<n;i++)
    {
        if ((a[i]<s)&& (i!=n)) {ans=ans*k % MOD;continue;}
        s=s+2;k=k+1;
    }
    //printf("%d %d\n",s,k);
    for (int i=1;i<=k;i++)
    {
        ans=ans*i % MOD;
    }
    printf("%d\n",(int) ans);
    return 0;
}
