#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int main() {
long long int a,b,c;
cin>>a>>b>>c;

if(a%2==0 || b%2==0 || c%2==0)
cout<<"0";
else
{
if(a>=b && a>=c)
cout<<b*c;
else 
if(a<=b && b>=c)
cout<<a*c;
else 
if(c>=a && b<=c)
cout<<a*b;
}
cout<<endl;
}
