#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,a,b;
    cin>>x>>a>>b;
    if(b<=a)
        cout<<"delicious"<<endl;
    if(b>a && b<=x+a)
        cout<<"safe"<<endl;
    if(b>x+a)
        cout<<"dangerous"<<endl;

    return 0;
}