#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    int sum=accumulate(v.begin(),v.end(),0);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int idx,val;
        cin>>idx>>val;
        cout<<sum+val-v[idx]<<endl;
    }
}
