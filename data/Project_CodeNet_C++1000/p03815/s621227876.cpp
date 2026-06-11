#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a;
    cin>>a;
    long long s=a/11*2;
    a%=11;
    if(a>=1&&a<=6)s++;
    if(a>=7&&a<=10)s+=2;
    cout<<s<<endl;
}