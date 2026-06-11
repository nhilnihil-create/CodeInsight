#include <iostream>

using namespace std;
const int nmax=100005;
long long sum,a[nmax],d[nmax];
int n,i;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%(1LL*n*(n+1)/2))
    {
        cout<<"NO";
        return 0;
    }
    long long k=(sum/((1LL*n*(n+1)/2)));
    a[n+1]=a[1];
    for(i=1;i<=n;i++)
    {
        d[i]=a[i+1]-a[i];
        if(k-d[i]<0||(k-d[i])%n)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
