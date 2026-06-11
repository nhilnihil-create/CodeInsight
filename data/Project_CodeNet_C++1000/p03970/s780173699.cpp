#include<iostream>
using namespace std;
int main()
{
string s,c="CODEFESTIVAL2016";
cin>>s;
int n=0;
for(int i=0;i<c.length();i++)
{
if(s[i]!=c[i])
n++;
}
cout<<n<<endl;
return 0;
}