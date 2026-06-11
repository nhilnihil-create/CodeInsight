#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2,s3,x;
    cin>>s1>>s2>>s3;
    s1[0]=s1[0]-32;
    s2[0]=s2[0]-32;
    s3[0]=s3[0]-32;
    x=x+s1[0];
    x=x+s2[0];
    x=x+s3[0];
    cout<<x<<endl;
    return 0;


}

