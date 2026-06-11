#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<long long> t(n);
    vector<long long> a(n);
    int i;
    for(i=0;i<n;i++)cin>>t.at(i)>>a.at(i);
    long long ans=0;
    long long ka=0;
    long long kt=0;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            ka=a.at(i);
            kt=t.at(i);
        }
        else
        {
            long long ha=(ka+a.at(i)-1)/a.at(i);
            long long ht=(kt+t.at(i)-1)/t.at(i);
            long long hm=max(ha,ht);
            ka=a.at(i)*hm;
            kt=t.at(i)*hm;
        }
    }
    ans=ka+kt;
    cout<<ans<<endl;
}
