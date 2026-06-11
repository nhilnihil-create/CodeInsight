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

void solve() {
    int n;cin>>n;
    ve<int> mp(9, 0);
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        mp[min(x,3200)/400]++;
    }
    int mn=0, mx=0;
    for(int i=0;i<8;i++) {
        if(mp[i]) mn++;
    }
    mx = mn + mp[8];
    if(mp[8])  
        mn = max(mn, 1);
    cout<<mn<<" "<<mx<<endl;
}

int main() {
    solve();
    return 0;
}