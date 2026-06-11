#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n,a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]+a[1]==a[2])
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}



