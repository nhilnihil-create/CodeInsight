#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int posa=0,posz=0;
    cin>>s;
    bool a = false ;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]=='A'&&!a)
        {
            posa=i;
            a = true;
        }
        if(s[i]=='Z')
            posz=i;
    }
    cout<<posz - posa +1 ;
    return 0;
}
