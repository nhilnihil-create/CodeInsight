#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

bool n,w,s,e;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str ss;
    cin>>ss;

    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]=='N')n=true;
        if(ss[i]=='W')w=true;
        if(ss[i]=='S')s=true;
        if(ss[i]=='E')e=true;
    }

    puts((n&&s&&!w&&!e)||(w&&e&&!n&&!s)||(n&&s&&w&&e)?"Yes":"No");

    return 0;
}
