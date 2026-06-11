#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str o,e;
    cin>>o>>e;

    for(int i=0;i<e.size();i++)cout<<o[i]<<e[i];

    if(o.size()>e.size())cout<<o[o.size()-1]<<"\n";

    return 0;
}
