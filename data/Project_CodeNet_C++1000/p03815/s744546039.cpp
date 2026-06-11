#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long abcbcbc;
    cin>>abcbcbc;
    long long s=abcbcbc/11*2;
    abcbcbc%=11;
    if(abcbcbc>=1&&abcbcbc<=6)s++;
    if(abcbcbc>=7&&abcbcbc<=10)s+=2;
    cout<<s<<endl;
}