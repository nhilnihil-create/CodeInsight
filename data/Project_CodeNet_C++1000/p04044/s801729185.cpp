#include<bits/stdc++.h>
using namespace std;
int main()
{
    multimap<string ,int> m;
    multimap<string ,int>:: iterator it;
    int n,l;
    cin>>n>>l;
    string s;
    for(int i=0;i<n;++i)
    {
        cin>>s;
        m.insert({s,i});
    }
    for(it=m.begin();it!=m.end();++it)
        cout<<it->first;
    cout<<endl;
    return 0;
}
