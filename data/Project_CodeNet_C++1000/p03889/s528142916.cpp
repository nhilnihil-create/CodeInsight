#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string rs=s;
    reverse(rs.begin(),rs.end());
    for(int i=0;i<s.size();i++)
    {
        if(rs[i]=='b')rs[i]='d';
        else if(rs[i]=='d')rs[i]='b';
        else if(rs[i]=='p')rs[i]='q';
        else if(rs[i]=='q')rs[i]='p';
    }
    if(s==rs)cout<<"Yes";
    else cout<<"No";
    return 0;
}