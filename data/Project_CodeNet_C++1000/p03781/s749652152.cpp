#include <bits/stdc++.h>
using namespace std;

long long x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>x;
    x*=2;
    long long t=sqrt(x);
    if(t*t+t>=x)
        cout<<t<<endl;
    else
        cout<<t+1<<endl;

    return 0;
}
