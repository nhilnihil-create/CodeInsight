#include <iostream>
using namespace std;
int main()
{
int a,b=0,c=0;
for(int i=0;i<3;i++)
{  
   cin>>a;
   if(a==5)
   {
      b+=1;
    }
    if(a==7){
      c+=1;
    }
}
if(b==2 && c==1)
{
cout<<"YES"<<endl;
}
else
{
  cout<<"NO"<<endl;
 }


return 0;
}