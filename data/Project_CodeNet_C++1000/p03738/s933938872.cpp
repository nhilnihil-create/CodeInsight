#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str a,b;
    cin>>a>>b;

    if(a.size()>b.size()) puts("GREATER");
    else if(a.size()<b.size()) puts("LESS");
    else 
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>b[i])
            {
                puts("GREATER");
                return 0;
            }
            else if(a[i]<b[i])
            {
                puts("LESS");
                return 0;
            }
        }
        puts("EQUAL");
    }

    return 0;
}
