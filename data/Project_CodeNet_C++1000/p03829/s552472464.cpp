#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,b,i,fatigue = 0;
    cin>>n>>a>>b;
    long long x[n + 1];
    for(i = 1; i <= n; i++)
        cin>>x[i];
    for(i = 2; i <= n; i++)
        fatigue+=min(b,a*(x[i] - x[i - 1]));
    cout<<fatigue<<endl;
    return 0;
}
