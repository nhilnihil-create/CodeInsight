#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int a,b,c,d,e,f;
    cin>>a>>b>>c;
    d=a+b;
    e=b+c;
    f=a+c;
    if((d<e) && (d<f)) cout<<d<<endl;
    else if((e<f) && (e<d)) cout<<e<<endl;
    else cout<<f<<endl;
    return 0;
}
