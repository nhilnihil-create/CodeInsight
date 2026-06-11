#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[5],b,c;
int main()
{
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+4);
    if(a[2]-a[1]==a[3]-a[2])
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}