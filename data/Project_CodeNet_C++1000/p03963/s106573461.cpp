#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll func(int a,int b)
{
    ll res=1;
    while(b>0)
    {
        if(b%2!=0)
        {
            res*=a;
        }
        b/=2;
        a*=a;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    ll ans=k*func(k-1,n-1);
    cout<<ans;
  	return 0;
}





