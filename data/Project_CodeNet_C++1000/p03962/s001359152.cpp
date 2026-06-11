#include <bits/stdc++.h>
using namespace std;
int main()
{
long a,b,c,d,r,f;
cin>>a>>b>>c;
if(a!=b && b!=c && c!=a) cout<<"3"<<endl;
else if((a==b&&b!=c)||(b==c&&c!=a)||(c==a&&a!=b))cout<<"2"<<endl;
else cout<<"1"<<endl;


return 0;
}
