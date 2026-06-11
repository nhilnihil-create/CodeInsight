#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;

    if(a.size()>b.size())
    {
        cout<<"GREATER\n";
    }
    else if(a.size()<b.size())
    {
        cout<<"LESS\n";
    }
    else if(a>b)
    {
        cout<<"GREATER\n";
    }
    else if(a<b)
    {
        cout<<"LESS\n";
    }
    else
    {
        cout<<"EQUAL\n";
    }
   //cout<<c<<endl;

    return 0;
}
