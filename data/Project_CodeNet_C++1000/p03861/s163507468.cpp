#include <iostream>
#include <string>

using namespace std;

int main()
{
 long long int a,b,x;
 cin>>a>>b>>x;

long long int count;

if(a==0 && b==0)
   count=1;
else if(a==0 && b>0)
    count=b/x+1;

else
    count=b/x-(a-1)/x;

cout<<count;
}
