#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool func(string a,string b)
{
    return a<b;
}

int main()
{
    vector<string>v;
    int n,l;
    cin>>n>>l;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),func);
    for(auto m: v)
        cout<<m;

}
