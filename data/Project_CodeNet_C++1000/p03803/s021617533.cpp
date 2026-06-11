#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    if (x==y)
        cout<<"Draw";
    else if (x==1)
        cout<<"Alice";
    else if (y==1)
        cout<<"Bob";
    else if (x>y)
        cout<<"Alice";
    else if (y>x)
        cout<<"Bob";

return 0;
}


