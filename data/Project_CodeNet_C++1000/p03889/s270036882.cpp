#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,tmp;
    cin>>s;
    tmp=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='b') s[i]='d';
        else if(s[i]=='d') s[i]='b';
        else if(s[i]=='q') s[i]='p';
        else if(s[i]=='p') s[i]='q';
    }
    if(s==tmp) printf("Yes\n");
    else printf("No\n");
    return 0;
}
