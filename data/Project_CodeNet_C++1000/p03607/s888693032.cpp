#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a;
    map<int,int>mp;
    set<int>s;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>a;
        s.insert(a);
        mp[a]++;
    }
    a=s.size();
    for(int i:s)
    {
        if(mp[i]%2==0)
         a--;
    }
    cout<<a;

}
