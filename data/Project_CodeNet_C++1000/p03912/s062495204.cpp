#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    map<int,int> mp2;
    map<int,int> m1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m1[a[i]]++;
        mp2[a[i]%m]++;
    }
    sort(begin(a),end(a));
    int ans=mp2[0]/2;
    mp2[0]=0;
    map<int,int> st;
    for(int i=1;i<=(m-1)/2;i++)
    {
        int p=min(mp2[i],mp2[m-i]);
        ans+=p;
        mp2[i]-=p;
        mp2[m-i]-=p;
    }
    if(m%2==0)
    {
        ans+=mp2[m/2]/2;
        mp2[m/2]=0;
    }
    for(auto it:m1)
    {
        int rem=mp2[it.first%m];
        int p=min(rem/2,it.second/2);
        ans+=p;
        mp2[it.first%m]-=2*p;


    }
    cout<<ans<<endl;

}