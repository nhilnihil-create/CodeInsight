#include<bits/stdc++.h>
using namespace std;
string a,b;
int much;
int main()
{
    cin>>a;
    b=a;
    much=a.size();
    reverse(a.begin(),a.end());//reverse函数nb！（撕心裂肺
    for(int i=0;i<much;i++)
    {
        if(a[i]=='b') a[i]='d';
        else if(a[i]=='d') a[i]='b';
        else if(a[i]=='p') a[i]='q';
        else if(a[i]=='q') a[i]='p';
    }
    if(a==b) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}