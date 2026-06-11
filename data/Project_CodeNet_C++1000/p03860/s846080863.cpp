#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
string s,a;
getline(cin,s);
a+=s[0];
for(int i=1;i<s.length();i++)
{
    if(s[i]==' ')
    {
        a+=s[i+1];
    }
}
cout<<a;
return 0;
}
