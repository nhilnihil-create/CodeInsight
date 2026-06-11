#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <limits>
#include<stdlib.h>
using namespace std;

int main()
{
string s; int n,x=0,m=0; cin>>n>>s;
for(int i=0;i<n;i++)
{
    if(s.at(i)=='I') {x++; if(x>m)m=x;}
    else {x--; if(x>m)m=x;}
}
cout<<m;
}
