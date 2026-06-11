#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    int n,s,t;
    cin>>n>>s>>t;
    int a,b;
    a=abs(n-s);
    b=abs(n-t);
    (a<b)?cout<<"A":cout<<"B";
}
