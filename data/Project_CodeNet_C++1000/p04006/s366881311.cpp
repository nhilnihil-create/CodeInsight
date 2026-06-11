#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<deque>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<map>
#include<stack>
#include<set>
#include<cstdlib>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<ctime>
#include<functional>
#include<sstream>
#include<deque>
using namespace std;
long long n,a[2020],b[2020],ans=2000010000000,x,cnt,i,j,k,m;
int main()
{
	memset(a,0x3f,sizeof(a));
    cin>>n>>x;
    for(i=0;i<n;i++)
        cin>>b[i];
    for(i=0;i<n;i++)
    {
        cnt=0;
        for(j=0;j<n;j++)
            a[j]=min(a[j],b[(j-i+n)%n]);
        for(j=0;j<n;j++)
            cnt+=a[j];
        ans=min(ans,i*x+cnt);
    }
    cout<<ans<<endl;
    return 0;
}