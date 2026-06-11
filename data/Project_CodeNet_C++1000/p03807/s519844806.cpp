#include<bits/stdc++.h>
using namespace std;
int n,a,ans=0;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
	{
        cin>>a;
        ans+=a;
    }
    if(ans%2==0)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}