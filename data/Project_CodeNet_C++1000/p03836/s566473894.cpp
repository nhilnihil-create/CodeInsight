#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,y1,x2,y2,i;
    cin>>x1>>y1>>x2>>y2;
    for(i=0; i<(y2-y1); i++)
        cout<<'U';
    for(i=0; i<(x2-x1); i++)
        cout<<'R';
    for(i=0; i<(y2-y1); i++)
        cout<<'D';
    for(i=0; i<(x2-x1); i++)
        cout<<'L';
    cout<<'L';
    for(i=0; i<(y2-y1+1); i++)
        cout<<'U';
    for(i=0; i<(x2-x1+1); i++)
        cout<<'R';
    cout<<"DR";
    for(i=0; i<(y2-y1+1); i++)
        cout<<'D';
    for(i=0; i<(x2-x1+1); i++)
        cout<<'L';
    cout<<"U"<<endl;
    return 0;
}

