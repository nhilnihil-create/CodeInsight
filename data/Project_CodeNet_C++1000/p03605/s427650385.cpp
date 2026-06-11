#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=n/10;
    int b=n%10;
    if(a==9 || b==9)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}
