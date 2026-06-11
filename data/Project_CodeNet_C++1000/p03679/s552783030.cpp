#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll x,a,b;
    cin >> x >> a >> b;
    if(a - b >= 0) puts("delicious");
    else if(b - a <= x) puts("safe");
    else puts("dangerous");
}