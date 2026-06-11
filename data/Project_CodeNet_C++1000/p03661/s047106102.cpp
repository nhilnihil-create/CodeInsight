#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,n,i,j,k,x;
    cin>>n;
    vector<ll>vi,v1,v2;
    ll sum1=0,sum2=0;
    for(i = 0 ;i<n ;i++)
    {
        cin>>x;
        vi.push_back(x);
        sum1+=x;
        if(i != n-1)
        v1.push_back(sum1);

    }
    ll mini =INT_MAX;
    for(i = n-1 ;i>=1;i--)
    {
        sum2+=vi[i];
        mini = min(mini,abs(sum2- v1[i-1]));
        //cout<<sum2<<" "<<vi[i-1]<<endl;
    }
    cout<<mini<<endl;
    return 0;
}
