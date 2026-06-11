#include<bits/stdc++.h>
using namespace std;
#define int long long int 
int32_t main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    if(m<2*n)
    cout<<m/2<<endl;
    else
    {
        int ans=n;
        m=m-n*2;
        //cout<<ans<<" "<<n<<" "<<m<<" "<<m/3<<endl;
        cout<<ans+(m/4)<<endl;
    }
}