#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    if ((x+y)<24)
        cout<<x+y;
    else if (x+y==24)
        cout<<0;
    else if (x+y>24)
        cout<<(x+y)-24;

return 0;
}


