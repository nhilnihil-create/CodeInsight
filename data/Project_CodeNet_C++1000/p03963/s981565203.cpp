#include <bits/stdc++.h>
using namespace std;;
typedef long long ll;

int main(){
    ll n,k;
    cin >> n >> k;
    cout << setprecision(18) << k*pow(k-1,n-1) <<endl;
}