#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int e=0,w=0,s=0,n=0;
    cin>>str;
    int siz=str.size();
    for(int i = 0; i<siz; i++)
    {
        if(str[i]=='E')
            ++e;
        else if(str[i]=='W')
            ++w;
        else if(str[i]=='S')
            ++s;
        else if(str[i])
            ++n;
    }
    bool f=true;;
    if(min(s,n)==0&&max(s,n)!=0) f = false;
    if(min(e,w)==0&&max(e,w)!=0) f = false;
    if(f)
        cout<<"Yes";
    else cout<<"No";
    return 0;
}
