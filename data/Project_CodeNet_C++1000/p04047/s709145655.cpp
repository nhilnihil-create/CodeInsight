#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e3+10;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++)cin>>a[i];
    sort(a+1,a+2*n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=a[2*i-1];
    }
    cout<<ans<<endl;
}