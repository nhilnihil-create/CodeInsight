#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

     ll a,b,c,d;
     cin>>a>>b>>c>>d;
     ll mi=min(b,d);
     ll ma=max(a,c);
     ll m=mi-ma;
    if(m>=0) cout<<m;
    else cout<<"0";
}






