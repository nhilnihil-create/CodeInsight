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

const ll MxN = 1e12;
void solve() {
    ll n,m;
    cin>>n>>m;
    if(n*2<=m) {
        cout<<((n*2)+m)/4<<endl;
    } else {
        cout<<m/2<<endl;
    }
}

int main() {
    solve();
    return 0;
}
