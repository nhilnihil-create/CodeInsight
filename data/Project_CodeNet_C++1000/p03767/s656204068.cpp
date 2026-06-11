#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
main()
{
    int n;
    cin>>n;
    int a[3*n];
    for(int i=0;i<3*n;i++)
        cin>>a[i];
    sort(a,a+3*n);
    ll sum=0;
    int p=0;
    for(int i=3*n-2;;i-=2)
    {
        sum+=a[i];
        p++;
        if(p==n)
            break;
    }
    cout<<sum;

}
