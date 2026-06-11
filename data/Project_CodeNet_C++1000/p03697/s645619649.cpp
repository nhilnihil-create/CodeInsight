#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,sum=0,c=0,f=0;
    cin>>a>>b;
    sum=a+b;
while(sum>0)
    {
        sum=sum/10;
        c++;
        if(c==2)
        {
            f=1;
            break;
        }

    }
    if(f==1)
    {
        cout<<"error"<<endl;

    }
    else
    {
        cout<<a+b<<endl;
    }


}
