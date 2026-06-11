#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,a,b;
    cin>>x>>a>>b;
    if(-a+b<=0){cout<<"delicious";}
    else if(-a+b<=x){cout<<"safe";}
    else{cout<<"dangerous";}
}
