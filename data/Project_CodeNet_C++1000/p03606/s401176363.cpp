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

void solve() {
    int n;cin>>n;
    int res=0;
    for(int i=0;i<n;i++) {
        int l,r;cin>>l>>r;
        res += r-l+1;
    }
    cout<<res<<endl;
}

int main() {
    solve();
    return 0;
}