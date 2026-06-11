#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int i;
    cin>>str;
    string jud=str;
    reverse(str.begin(),str.end());//交换
    for(i=0;i<str.size();i++)
    {
        if(str[i]=='b') str[i]='d';
        else if(str[i]=='d') str[i]='b';
        else if(str[i]=='p') str[i]='q';
        else if(str[i]=='q') str[i]='p';
    }
    if(str==jud) printf("Yes");
    else printf("No");
    return 0;
}