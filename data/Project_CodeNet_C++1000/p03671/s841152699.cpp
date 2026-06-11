#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    int all,biggest,ans;
    cin>>a>>b>>c;
    all=a+b+c;
    biggest=max(a,max(b,c));
    ans=all-biggest;
    cout<<ans<<endl;
    return 0;
}