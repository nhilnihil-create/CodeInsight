#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s,f="CODEFESTIVAL2016";

    cin>>s;
    int r=0;
    for(int i=0;i<16;i++)
    {
        if(s[i]==f[i])
            continue;
        else
            r++;
    }

    cout<<r;
    return 0;
}
