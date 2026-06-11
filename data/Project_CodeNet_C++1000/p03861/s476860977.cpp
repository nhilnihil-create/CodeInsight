#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,x,p,q,ans;
    cin>>a>>b>>x;
    p=b/x;
    q=a/x;
    ans=p-q;

    if(a%x==0)
    {
        ans++;
    }
    cout<<ans<<endl;

    return 0;

}
