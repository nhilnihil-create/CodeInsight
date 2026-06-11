#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <limits>
#include<stdlib.h>
using namespace std;

int main()
{
string s; int z=1; cin>>s;
for(char i='a';i<='z';i++)
{
    if((s.find(i))== std::string::npos) {cout<<i;  z=0; break;}
}
if(z==1) cout<<"None";
}
