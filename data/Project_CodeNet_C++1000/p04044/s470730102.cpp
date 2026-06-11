#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,l;
    cin>>n>>l;
    vector<string>v;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(string x:v)
        cout<<x;
    cout<<"\n";
}
