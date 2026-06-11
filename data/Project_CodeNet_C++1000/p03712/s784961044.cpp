#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    char a[x][y];
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
        cin>>a[i][j];

    for(int i=0;i<y+2;i++)
        cout<<"#";
    cout<<endl;

    for(int i=0;i<x;i++){
            cout<<"#";
        for(int j=0;j<y;j++)
        cout<<a[i][j];
    cout<<"#\n";

    }
   for(int i=0;i<y+2;i++)
        cout<<"#";
    return 0;
   }