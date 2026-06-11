#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{
    cin>>a;
    int ans=0;
    int p=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='g')
        {
            if(p>0)
            {
                ans++;
                p--;
            }
            else
            {
                p++;
            }
        }
        else
        {
            if(p>0)
                p--;
            else
            {
                p++;
                ans--;
            }

        }
    }
    cout << ans << endl;
    return 0;
}