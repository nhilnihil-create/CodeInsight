#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,z;
    int a[10]={0};
    cin>>x>>y>>z;
    a[x]++;
    a[y]++;
    a[z]++;
    if(a[5]==2&&a[7]==1)
        cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    return 0;
}