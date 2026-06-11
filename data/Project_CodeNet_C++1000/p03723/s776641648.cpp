#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b,n,c,i,x,y,z,w=0;
  cin>>a>>b>>c;
  if(a==b&&b==c&&c%2==0)
  {
     cout<<"-1"<<endl;
     return 0;
  }
  while(a%2==0 && b%2==0 && c%2==0)
  {
     x=a,y=b,z=c;
     a=(y/2)+(z/2);
     b=(z/2)+(x/2);
     c=(x/2)+(y/2);
     w++;
  }
 cout<<w<<endl;
 return 0;

}
