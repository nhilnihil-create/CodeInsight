#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>b){cout<<b*c+d*(a-b);}
    else{cout<<a*c;}
}