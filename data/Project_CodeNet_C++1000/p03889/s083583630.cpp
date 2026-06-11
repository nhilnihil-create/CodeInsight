#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    string s,v;
    cin>>s;v=s;
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();++i)
        v[i]=='b'?v[i]='d':v[i]=='d'?v[i]='b':v[i]=='p'?v[i]='q':v[i]='p';
    cout<<(s==v?"Yes":"No");
    return 0;
}