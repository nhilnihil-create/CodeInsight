#include<bits/stdc++.h>
using namespace std;
int main()
{   int a,b,c,d;
    cin>>a>>b>>c>>d;
      if(max(b,d)-max(a,c)-abs(b-d)>0)
      cout<<max(b,d)-max(a,c)-abs(b-d)<<"\n";
      else
      cout<<0<<"\n";
    return 0;
    
    
    
}