#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll q,h,s,d,n;
    cin>>q>>h>>s>>d>>n;
    cout<<(n/2) * min(8*q,min(4*h,min(2*s,d))) + (n%2) * min(4*q,min(2*h,s));
}