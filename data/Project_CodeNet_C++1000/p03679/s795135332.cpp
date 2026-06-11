#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
int main()
{
   string d="delicious",s="safe",dd="dangerous";
    int x,y,z;
    cin>>x>>y>>z;
    if(z<=y)
      cout<<d;
    else if(abs(y-z)<=x)
      cout<<s;
    else
      cout<<dd;
    cout<<nl;
    return 0;
}
