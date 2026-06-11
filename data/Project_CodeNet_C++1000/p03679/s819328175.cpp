#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,a,b,temp;
    cin>>x>>a>>b;
    temp=a-b;
    if(temp>=0)
    {
        cout<<"delicious";
    }
    else
    {
        temp=abs(temp);
        temp=x-temp;
        if(temp>=0)
            cout<<"safe";
        else
            cout<<"dangerous";
    }
    return 0;
}
