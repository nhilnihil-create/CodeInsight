#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
string s; 
int main()
{
    cin>>s;
    int len=s.length()-2;
    cout<<s[0]<<len<<s[s.length()-1];
    
    return 0;
}