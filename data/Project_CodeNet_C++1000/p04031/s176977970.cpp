#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,a;
    cin>>n;
    vector<int>v;
    double sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
        sum+=a;
    }
    int x=ceil(sum/n);
    int y=floor(sum/n);
    int ans1=0,ans2=0;

    for(int i=0;i<n;i++)
    {
        ans1+=(v[i]-x)*(v[i]-x);
    }
    for(int i=0;i<n;i++)
    {
        ans2+=(v[i]-y)*(v[i]-y);
    }
    cout<<min(ans1,ans2)<<"\n";
}
