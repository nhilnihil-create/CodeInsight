#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#define LL long long int
const int N = 100005;
using namespace std;
LL n,A,B;
LL a[N];

bool judge(LL x)
{
    LL temp=x*B;
    LL sub=A-B;
    LL sum=0;
    for(LL i=n; i>=1; i--)
    {
        if(a[i]>temp)
        {
            if((a[i]-temp)%sub)
                sum+=(a[i]-temp)/sub+1;
            else
            sum+=(a[i]-temp)/sub;
        }
    }
    if(sum<=x)
        return true;
    return false;

}

int main()
{

    cin>>n>>A>>B;
    LL right=0;
    for(LL i=1; i<=n; i++)
    {
        cin>>a[i];
        right+=a[i]/B+1;
    }

    sort(a+1,a+1+n);
    LL left=1;
    while(left<right)
    {
        LL mid=(left+right)/2;
        if(judge(mid))
            right=mid;
        else
            left=mid+1;
    }
    cout<<left<<endl;
    return 0;

}

