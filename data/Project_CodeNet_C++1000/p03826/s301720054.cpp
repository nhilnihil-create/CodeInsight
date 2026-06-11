#include<bits/stdc++.h>
using namespace std;
int main()
{
int A,B,C,D;
cin>>A>>B>>C>>D;
int ar1,ar2;
ar1=A*B;
ar2=C*D;
if(ar1>ar2)
cout<<ar1;
else
if(ar1<ar2)
cout<<ar2;
else
if(ar1==ar2)
cout<<ar1;
return 0;
}
