#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
long long n,a,b;
long long  c[51000000];
bool pd(int mid)
{
    long long shanghai=b*mid;
    long long sum=0;
    for (long long i=0;i<n;i++)
    {
        if (c[i]>shanghai)
        {  if (c[i]%(a-b)!=0)
            sum=sum+ (c[i]-shanghai)/(a-b)+1;
        else sum=sum+(c[i]-shanghai)/(a-b);
        }
    }
    if (sum<=mid) return false;
    else return true;
}
int main()
{
    cin>>n>>a>>b;
    for (long long i=0;i<n;i++)
        cin>>c[i];
        long long f=1e9;
    long long start=0,endd=1e9;
    while (start<=endd)
    {
        long long mid=(start+endd)>>1;
        if (!pd(mid))
        {
            endd=mid-1;
            f=min(f,mid);
        }
        else start=mid+1;
    }
    cout<<f<<endl;
    return 0;
}
