#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+100,INF=99999999,MOD=1e9+7;
long long x[MAX],y[MAX],n,m;

int main()
{	cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>x[i];
    for(int i=1;i<=m;++i)
        cin>>y[i];
    long long ax=0,ay=0;
    for(int i=1;i<=n;++i)
        ax=(ax+((i-1)*x[i]-(n-i)*x[i]))%MOD;
    for(int i=1;i<=m;++i)
        ay=(ay+((i-1)*y[i]-(m-i)*y[i]))%MOD;
    cout<<ax%MOD*ay%MOD<<endl;
    return 0;
}