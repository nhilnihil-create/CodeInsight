#include <bits/stdc++.h>

using namespace std;

int main()
{
   int w,a,b,s;
    cin>>w>>a>>b;
    if(b>a)
   {
     s=b-a;
   }
   else {
      s=a-b;
   }
    if(s>w)
    {
        cout<<s-w<<"\n";
    }
     else
     {
         cout<<"0"<<"\n";
     }
    return 0;
}
