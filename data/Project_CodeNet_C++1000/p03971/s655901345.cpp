#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int p,q;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,a,b;
    cin>>n>>a>>b;

    str s;
    cin>>s;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            p++;
            puts(p<=a+b?"Yes":"No");
        }
        else if(s[i]=='b')
        {
            q++;
            if(q<=b)p++;
            puts(p<=a+b&&q<=b?"Yes":"No");
        }
        else if(s[i]=='c')
        {
            printf("No\n");
        }
    }

    return 0;
}
