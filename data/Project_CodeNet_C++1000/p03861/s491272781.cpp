#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,x,ans;
    while(cin>>a>>b>>x)
    {
        if(a%x==0)
        {
            ans=abs((a/x)-(b/x));
            ans=ans+1;
        }
        else
            ans=abs((a/x)-(b/x));

        cout<<ans<<endl;
    }
}
