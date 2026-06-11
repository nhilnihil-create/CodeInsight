#include<bits/stdc++.h>
#include<complex>
#include<cassert>
#include<array>
#define ll long long
#define endl "\n"
#define pb push_back
#define READ(FILE) freopen(FILE,"r",stdin)
#define WRITE(FILE) freopen(FILE,"w",stdout)
#define loop(i,s,e) for(int i=s;i<e;i++)
#define mego fast();
#define cp(a,b) (conj(a)*b).imag()
using namespace std;
void fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll lcm(ll x, ll y)
{
    return (x*y)/__gcd(x,y);
}
int main()
{
mego
int a,b;
cin>>a>>b;
cout<<(a+b)%24;
return 0;
}
