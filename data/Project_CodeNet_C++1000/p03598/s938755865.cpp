#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        ans+=min(2*abs(a-k),2*a);
    }
    cout<<ans<<"\n";
    
}