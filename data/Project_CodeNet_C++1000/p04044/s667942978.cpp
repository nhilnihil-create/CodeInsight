#include<bits/stdc++.h>
using namespace std;


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main()

{
    optimize();

    int n,l;
    vector<string> v;
    string s;
    cin>>n>>l;
    for(int i=0;i<n;i++)
    {
       cin>>s;
        v.push_back(s);
    }
    sort( v.begin(),v.end());
    for(string u:v )
        cout<<u;










    return 0;
}

