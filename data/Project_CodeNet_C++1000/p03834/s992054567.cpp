#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<19;i++)
    {
        if(s[i]==',') s[i]=' ';
        else if(s[i]==' ') s[i]=',';
    }
    cout<<s<<endl;

    return 0;
}
