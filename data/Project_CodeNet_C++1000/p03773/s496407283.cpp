#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repr(i,x,n) for(int i=x; i<(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define INF 1e9
typedef long long ll;
using VI = vector<int>;
using VS = vector<string>;
using graph = vector<vector<int>>;
int main()
{
ll a,b;
cin>>a>>b;
ll ans=a+b;
if (ans>=24)
{
    ans%=24;
}
cout<<ans<<endl;
    return 0;
}