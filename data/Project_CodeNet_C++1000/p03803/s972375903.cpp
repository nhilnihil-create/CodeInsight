#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
int main()
{
    int a,b;
    cin>>a>>b;
    if(a!=1&&b!=1)
    {
       if(a>b)
         cout<<"Alice";
       else if(b>a)
         cout<<"Bob";
       else
         cout<<"Draw";
    }
    else if(a==1&&b!=1)
      cout<<"Alice";
    else if(b==1&&a!=1)
      cout<<"Bob";
    else
      cout<<"Draw";
    cout<<nl;
    return 0;
}
