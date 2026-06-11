#include<bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include<iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ll a,b,c,d,e,f,g;
	cin >> a>> b>> c>> d>> e>> f >> g;
    
    ll s=min({a,d,e});
    a-=s;
    d-=s;
    e-=s;
    int k = a%2+d%2+e%2;
    if(s==0)k=0;
    int ma = max(k-1,0);
    ll ans=3*s+(a/2)*2+b+(d/2)*2+(e/2)*2+ma;
    cout << ans << endl;
}