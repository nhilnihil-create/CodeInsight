#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int m=1e9;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        if(n<=k)
        {
            cout<<n*x<<endl;
        }
        else
        {
            cout<<(k)*x+(n-k)*y<<endl;
        }
    }
    return 0;
}
