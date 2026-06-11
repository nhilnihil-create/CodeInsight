#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    if(a[a.size()-1]==b[0])
    {
       if(b[b.size()-1]==c[0])
         cout<<"YES";
       else
         cout<<"NO";
    }
    else
      cout<<"NO";
    cout<<nl;
    return 0;
}
