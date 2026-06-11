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
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator 

int ar[51];
void solve() {
    int n, k; cin>>n>>k;
    for(int i=0;i<n;i++) cin>>ar[i];
    sort(ar, ar+n);
    int res=0;
    for(int i=n-1;i>=n-k;i--) {
        res += ar[i];
    }
    cout<<res<<endl;
}

int main() {
    solve();
    return 0;
}