#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b,c,s[4];
cin>>a>>b>>c;
s[0]=a;
s[1]=b;
s[2]=c;
sort(s,s+3);
if((s[0]+s[1])==s[2]) cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}
