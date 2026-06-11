#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,a,b;
    cin>>n>>a>>b;
    ll min = (n - 1) * a + b;
    ll max = (n - 1) * b + a;
    if((n == 1 && a != b) || a > b) cout<< 0 <<"\n";
    else cout<< max - min + 1 << "\n";
}