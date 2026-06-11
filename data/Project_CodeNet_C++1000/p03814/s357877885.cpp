#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
#include <iostream>
using namespace std;
 
int main()
{
string s;  int x,y; cin>>s;
x=s.find("A");
y=s.rfind("Z");
cout<<y-x+1;
}
