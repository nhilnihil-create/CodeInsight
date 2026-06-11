#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,a,b;
    cin>>x>>a>>b;
    a=abs(a-x);
    b=abs(b-x);
    if(min(a,b)==a)
      cout<<"A";
      else cout<<"B";

return 0;
}


