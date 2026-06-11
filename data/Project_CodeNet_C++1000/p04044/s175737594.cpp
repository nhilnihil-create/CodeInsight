#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,l;
    string s;
    cin>>n>>l;
    vector<string>v;
    for(i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++)
        cout<<v[i];
    cout<<endl;
}
