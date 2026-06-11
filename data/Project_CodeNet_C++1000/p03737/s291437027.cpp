#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    string s1, s2, s3;

    cin>>s1>>s2>>s3;
    s1=toupper(s1[0]);
    s2=toupper(s2[0]);
    s3=toupper(s3[0]);
    cout<<s1<<s2<<s3<<endl;
    return 0;
}