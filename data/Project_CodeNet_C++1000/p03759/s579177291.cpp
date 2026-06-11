#include <bits/stdc++.h>
using namespace std;
string beauty(int a,int b,int c)
{
    if(b-a==c-b)
        return "YES";
    else
        return "NO";
}
int main()
{
    int a,b,c;
    string res;
    cin>>a>>b>>c;
    res=beauty(a,b,c);
    cout<<res<<endl;
    return 0;
}