#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[2*n];
    for(int i=0;i<2*n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+2*n,greater<int>());
    ll sum=0;
    for(int i=0;i<2*n;i+=2)
    {
        sum += min(a[i],a[i+1]);
    }
    cout<<sum<<"\n";

    return 0;
}

