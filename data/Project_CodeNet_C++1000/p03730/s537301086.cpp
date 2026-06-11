#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define log(x,b) (log(b)/log(x))
#define rep(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int mod=1e9+7;
int32_t main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int g=__gcd(a,b);
    if(c%g==0)puts("YES");
    else puts("NO");

    return 0;
}
