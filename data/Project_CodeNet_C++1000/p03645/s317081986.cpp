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
    int n, m; cin>>n>>m;
    set<pair<int, int> > s;
    for(int i=0;i<m;i++) {
        int a, b; cin>>a>>b;
        s.insert({a,b});
    }
    for(int i=0;i<n;i++) {
        if(s.count({1,i}) && s.count({i,n})) {
            cout<<"POSSIBLE\n";
            return;
        }
    }
    cout<<"IMPOSSIBLE\n";
}

int main() {
    solve();
    return 0;
}