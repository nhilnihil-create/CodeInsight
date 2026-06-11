#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int n,l,i;
    string s,p;
    vector<string>v;
    cin>>n>>l;
    for(i=0;i<n;i++)
    {
        cin>>s;
        v.pb(s);
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
        p+=v[i];
    cout<<p;
}
