#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>
using namespace std;
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repb(i,r,l) for(int i=r;i>l;i--)
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

const int MxN=4e8+1;
pair<ll,ll> a[50], b[50];
void solve() {
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    for(ll i=0;i<m;i++) cin>>b[i].first>>b[i].second;
    for(ll i=0;i<n;i++) {
        ll min=MxN,k;
        for(ll j=0;j<m;j++) {
            ll d = abs(b[j].second-a[i].second)+abs(b[j].first-a[i].first);
            if(d < min) {
                min = d;
                k = j;
            }
        }
        cout<<k+1<<endl;
    }
}

int main() {
    solve();
    return 0;
}