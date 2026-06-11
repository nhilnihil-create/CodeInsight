#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;




int main() {
    int n,k;
    cin >> n >> k;
    cout << (ll)pow(k-1,n-1)*k;
}

