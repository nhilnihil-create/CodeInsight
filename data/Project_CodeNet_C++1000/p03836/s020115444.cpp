#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
    int x,y,tx,ty;
    cin>>x>>y>>tx>>ty;
    int dx=tx-x;
    int dy=ty-y;
    cout<<string(dy,'U')<<string(dx,'R');
    cout<<string(dy,'D')<<string(dx,'L');
    cout<<"L"<<string(dy+1,'U')<<string(dx+1,'R')<<"D";
    cout<<"R"<<string(dy+1,'D')<<string(dx+1,'L')<<"U";

}