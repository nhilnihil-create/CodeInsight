#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 
int  main(){
int n;
cin >> n;
ll maxx = 0,minn=10e16;
for(int i=0;i<n;i++){
    ll a,b;
    cin >> a >> b;
    maxx = max(a,maxx);
    minn = min(minn,b);
}
ll ans = maxx+minn;
cout << ans << endl;
}
 
