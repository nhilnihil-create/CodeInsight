#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k,ans,i;
    cin>>n>>k;
    ans=k;//for 1st ball we can select any color
    for(i=2;i<=n;i++){
        ans*=k-1;//rest of the balls can be selected in k-1 ways
    }
    cout<<ans;
    return 0;
}
