#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<map>
#include<array>
#include<cstring>
#include<numeric>
#include<string>
#include<set>
#include<cstdio>
#include<cmath>
#include<unordered_map>
#include<bitset>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
   
    ll a,b,x;
    cin>>a>>b>>x;
    ll res;
    if(a==0) res = (b/x) + 1;
    else res = (b/x) - ((a-1)/x);
    cout<<res<<"\n";
    return 0;
}
