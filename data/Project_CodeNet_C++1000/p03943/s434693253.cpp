#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int s[3];
    cin>>s[0]>>s[1]>>s[2];
    sort(s,s+3);
    if(s[0]+s[1]==s[2])
        cout<<"Yes"<<endl;
    else cout<<"No";

}