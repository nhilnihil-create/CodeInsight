#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,x,sum;
    cin>>x>>a>>b;
    sum=x+a;
    if(b>sum)
        cout<<"dangerous"<<endl;
    else
    {
        if(sum>=b&&x>b)
            cout<<"delicious"<<endl;
        else
            cout<<"safe"<<endl;
    }
}