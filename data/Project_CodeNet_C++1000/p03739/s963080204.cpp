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
const int MxN = 1e5;
ll ar[MxN];
int n;
ll solve() {    
    ll res = 0;
    ll sum = 0;
    for(int i=0;i<n;i++) {
        if (i % 2 == 0) {
            if (sum + ar[i] <= 0) {
                res += llabs(sum + ar[i] - 1);
                sum = 1;
            } else 
                sum += ar[i];
        } else {
            if (sum + ar[i] >= 0) {
                res += llabs(sum + ar[i] + 1);
                sum = -1;
            } else 
                sum += ar[i];
        }
    }
    return res;
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>ar[i];
    ll a =solve();
    for(int i=0;i<n;i++) ar[i] = -ar[i];
    ll b =solve();
    cout<<min(a, b)<<endl;
    return 0;
}