#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l=s.length(),i,c=0;
    for(i=0;i<l-1;i++)
    {
        if(s[i]!=s[i+1]) c++;
    }
    cout<<c<<endl;
    return 0;
}
