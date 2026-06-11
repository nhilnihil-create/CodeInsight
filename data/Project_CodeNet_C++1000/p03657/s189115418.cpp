#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    if((m+n)%3==0||n%3==0||m%3==0) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}