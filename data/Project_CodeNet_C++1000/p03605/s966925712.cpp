#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s.find('9')!=-1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}