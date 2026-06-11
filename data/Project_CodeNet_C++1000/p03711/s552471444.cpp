#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    if(x==2||y==2)
        cout<<"No";
    else if(y==11||y==9||y==6||y==4)
    {
        
        if(x==9||x==6||x==4)
        cout<<"Yes";
        else
            cout<<"No";
    }
    else
        {
            if(x!=9&&x!=6&&x!=4&&x!=11)
                cout<<"Yes";
            else
                cout<<"No";
        }
}