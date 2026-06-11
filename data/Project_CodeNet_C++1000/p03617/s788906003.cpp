#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll q,h,s,d,n,cost,low;
    cin>>q>>h>>s>>d>>n;
    low=min(min(min(8*q,4*h),2*s),d);
    cost=low*(n/2)+(n%2)*min(min(4*q,2*h),s);
    cout<<cost;
}