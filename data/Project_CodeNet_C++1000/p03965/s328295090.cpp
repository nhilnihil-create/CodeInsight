#include <bits/stdc++.h>
using namespace std;
int main()
{
long long a,b,i,c=0;
string s;
cin>>s;
for(i=0;i<s.size();i++)
{
	if(s[i]=='g') c++;
	else c--;
}
cout<<c/2<<endl;
return 0;
}
