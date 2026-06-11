#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s; int g=0,p=0,w=0,l=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='g')
        {
            if(g>p)
            {
                w++;
                p++;
            }
            else g++;
        }
        else if(s[i]=='p')
        {
            if(g>p) p++;
            else
            {
                g++;
                l++;
            }
        }
    }
    cout<<w-l<<endl;
    return 0;
}
