#include<iostream>
using namespace std;
int main()
{
int a[3],i;
for(i=0;i<3;++i)
cin>>a[i];
int diff1,diff2;
diff1=a[1]-a[0];
diff2  =a[2]-a[1];
if(diff2==diff1)
cout<<"YES";
else
cout<<"NO";
return 0;


}