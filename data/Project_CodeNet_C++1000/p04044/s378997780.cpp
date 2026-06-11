#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,l;
    cin>>n>>l;

    vector<str> s;
    for(int i=0;i<n;i++)
    {
        str is;
        cin>>is;
        s.push_back(is);
    }

    sort(s.begin(),s.end());

    for(int i=0;i<n;i++)cout<<s[i];

    cout<<"\n";

    return 0;
}
