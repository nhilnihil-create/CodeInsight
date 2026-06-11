#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <map>
#include <vector>
//#include <unordered_map>
//#include <unordered_set>
#include <stack>
#include <set>
#include <queue>
#include <list>

using namespace std;
long long mod=1e9+7;
long long k[100005];
int f[100005];
int main()
{
    int n,z;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&f[i]);
    f[1]=1;
    if(f[2]>2) f[2]=3;
    k[1]=1;
    k[2]=2;
    for(int i=3;i<=n;++i)
    {
        if(f[i]>f[i-1]+1) f[i]=f[i-1]+2;
        k[i]=(k[i-1]*(i-(2*(i-1)-f[i-1])/2))%mod;
    }
    cout<<k[n]<<endl;
    return 0;
}
