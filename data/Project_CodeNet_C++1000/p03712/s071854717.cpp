#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    int h,w;
    cin>>h>>w;
    vector<string> v(h);
    for(int i=0;i<h;i++)
    cin>>v.at(i);
     w+=2;
    for(int i=0;i<w;i++)
    cout<<"#";
    cout<<endl;
    for(int i=0;i<h;i++)
    cout<<"#"<<v[i]<<"#"<<endl;
     for(int i=0;i<w;i++)
    cout<<"#";
    cout<<endl;
    return 0;
}