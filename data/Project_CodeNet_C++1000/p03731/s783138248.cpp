#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
using namespace std;
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repb(i,r,l) for(int i=r;i>l;i--)
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator
const int SIZE=2e5;
ll ar[SIZE];
void solve() {
    ll n, t;
    cin>>n>>t;
    for(int i=0;i<n;i++) cin>>ar[i];
    ll res=0;
    for(int i=1;i<n;i++) {
        if(ar[i]-ar[i-1] < t) res += ar[i]-ar[i-1];
        else res += t;
    }
    cout<<res+t<<endl;
}

int main() {
    solve();
    return 0;
}