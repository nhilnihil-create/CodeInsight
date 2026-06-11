#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, n) for(i = 0; i < n; i++)

int main(){
    ll X, t;
    cin >> X >> t;
    cout << ((X - t > 0) ? X - t : 0) << '\n';
    return 0;
}