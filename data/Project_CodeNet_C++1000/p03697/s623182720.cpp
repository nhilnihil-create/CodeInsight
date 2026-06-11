#include<bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a+b>=10||a>10||b>10) cout<<"error"<<endl;//如果a+b大于等于10，输出error
    else cout<<a+b<<endl;//否则输出a+b
    return 0;
}