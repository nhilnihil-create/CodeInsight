#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,x;
    cin>>x>>a>>b;
    if((x+1+a)-b>=1)
    {
        if(b>x)
        {
            cout<<"safe"<<endl;

        }
        else
            cout<<"delicious"<<endl;
    }

    else
    {
        cout<<"dangerous"<<endl;
    }



}
