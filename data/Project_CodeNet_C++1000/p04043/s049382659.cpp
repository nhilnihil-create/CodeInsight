#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int s[]={a,b,c};
    int x=0,y=0;
    for(int i=0;i<3;i++){
        if(s[i]==5)
            x++;
        else if(s[i]==7)
            y++;
    }

    if(x==2&&y==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}