#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=10001;
int a[maxn],b[maxn],n,ans,x;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
signed main()
{
    cin>>n>>x;
    int m=n/gcd(n,x),y=x/gcd(n,x);
    cout<<(m-1)*3*gcd(n,x);

}