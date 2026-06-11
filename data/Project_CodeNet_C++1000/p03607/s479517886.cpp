
#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{
    int n;
    cin>>n;
  int ans=0;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>ans;
        m[ans]++;
    }
    ans=0;
    for(auto i:m)
    if(i.second%2)
    ans++;

    cout<<ans<<endl;
}