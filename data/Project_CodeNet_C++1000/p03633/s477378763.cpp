#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

ll gcd(ll a, ll b) {
    if(b==0) return a;
    a %= b;
    return gcd(b, a);
}
void solve() {
    int n;cin>>n;
    ll res=1;
    for(int i=0;i<n;i++) {
        ll x; cin>>x;
        res /= gcd(res, x);
        res *= x;
    }
    cout<<res<<endl;
}

int main() {
    solve();
    return 0;
}