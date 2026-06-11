#include<bits/stdc++.h>
using namespace std;

int main()
{
    int64_t ans1,ans2,a,b,x;

    cin >> a >> b>>x;

    ans2=b/x;
    ans1=a/x;
    if(a%x==0)cout << ans2-ans1+1 <<endl;
    else cout << ans2-ans1 <<endl;

}