#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str sa,sb,sc;cin>>sa>>sb>>sc;
    deque<int> d[3];
    for(int i=0;i<sa.size();i++)d[0].push_back(sa[i]-'a');
    for(int i=0;i<sb.size();i++)d[1].push_back(sb[i]-'a');
    for(int i=0;i<sc.size();i++)d[2].push_back(sc[i]-'a');

    int t=0;

    char ans='a';

    for(;;)
    {
        if(d[t].size()==0){ans=t+'A';break;}
        int f=t;
        t=d[t][0];
        d[f].pop_front();
    }

    cout<<ans<<"\n";

    return 0;
}
