#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nl '\n'
int main()
{
    optimize();
    int n,l;
    cin>>n>>l;

    vector<string>v(n);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(auto u:v){
        cout<<u;
    }
  return 0;
}

