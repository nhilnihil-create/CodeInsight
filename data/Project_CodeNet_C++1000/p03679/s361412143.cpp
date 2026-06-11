#include<bits/stdc++.h>
using namespace std;
int main()
{
long long a,b,c,d,e,f,g,h;
cin>>a>>b>>c;
if(b-c>=0)
{

cout<<"delicious";
}
else
{
d=abs(b-c);
if(d<=a)
cout<<"safe";
else
cout<<"dangerous";


}



}
