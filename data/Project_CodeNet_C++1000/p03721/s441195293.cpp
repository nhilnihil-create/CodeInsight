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
const int MxN= 1e5+1;
ll ar[MxN];
void solve() {
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        ll a,b;
        cin>>a>>b;
        ar[a] += b;
    }
    int i=0;
    while(k>0) {
        k -= ar[i];
        i++;
    }
    cout<<i-1<<endl;
}

int main() {
    solve();
    return 0;
}