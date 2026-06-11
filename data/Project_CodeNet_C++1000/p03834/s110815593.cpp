#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    char c;
    c=char(32);
    s[5]=c,s[13]=c;
    cout<<s;
    return 0;
}
