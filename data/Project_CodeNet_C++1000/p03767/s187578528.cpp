#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, i, ans=0, l=2;
    int a[300005];
    cin>>n;
    for(i=0; i<3*n; i++)
        cin>>a[i];
    sort(a, a+(3*n));
    for(i=0; i<n; i++)
    {
        ans+=a[3*n-l];
        l+=2;
    }
    cout<<ans;
}
