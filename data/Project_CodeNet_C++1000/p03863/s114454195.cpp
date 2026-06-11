#include<bits/stdc++.h>
using namespace std;
string a;
int b;
int main()
{
cin>>a;
b=a.size();
if(a[0]==a[b-1])
{
if(b%2==0)
{
cout<<"First"<<endl;
return 0;
}
else
{
cout<<"Second"<<endl;
return 0;
}
}
else
{
if(b%2==0){
cout<<"Second"<<endl;
return 0;
}
else
{
cout<<"First"<<endl;
return 0;
}
}
}