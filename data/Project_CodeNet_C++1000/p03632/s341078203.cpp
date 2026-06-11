#include<bits/stdc++.h>
using namespace std;

#define int long long int


int32_t main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<(-max(a,c)+min(b,d)<0?0:-max(a,c)+min(b,d))<<endl;
}