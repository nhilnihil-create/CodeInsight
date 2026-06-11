#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x=-1,y=-1,i;
    string str;
    cin>>str;
    for(i=0; str[i]; i++)
        if(str[i]=='A'){
            x=i;
            break;}
    for(i=str.length()-1;i>=0;i--)
        if(str[i]=='Z'){
            y=i;
            break;}
    if(x==-1 || y==-1 || y<x)
        cout<<0<<endl;
    else
        cout<<(y-x+1)<<endl;
    return 0;
}
