#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k;
    long a,b,c;
    a=k/50+50;     //要特别处理的数的大小
    b=k%50;       //要特别处理的数的个数
    c=a-b-1;      //正常相等的个数
    cout<<50<<endl;
    for(int i=0;i<50;i++)
    {
        if(i<b)
        {
            if(i==0)
            cout<<a;
            else
            cout<<" "<<a;
        }
        else
        {
            if(i==0)
            cout<<c;
            else
            cout<<" "<<c;
        }
    }
    cout<<endl;
    return 0;
}
