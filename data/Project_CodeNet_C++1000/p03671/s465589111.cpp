#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
int main()
{
    long x[4];
    cin>>x[0]>>x[1]>>x[2];
    sort(x,x+3);
    cout<<x[0]+x[1];
    cout<<nl;
    return 0;
}
