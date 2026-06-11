#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
using namespace std;
 
int main()
{
int h,w; string s[1000]; cin>>h>>w;
for(int i=0; i<h;i++) cin>>s[i];
for(int i=0;i<w+2;i++) cout<<"#"; cout<<"\n";
for(int i=0;i<h;i++)
{
    cout<<"#"<<s[i]<<"#"<<"\n";
}
for(int i=0;i<w+2;i++) cout<<"#";
return 0;
}