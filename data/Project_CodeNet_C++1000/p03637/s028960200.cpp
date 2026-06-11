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
    int c=0;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        if(x%2 == 0) c++;
        if(x%4 == 0) c++;
    }
    if(c/2 >= n/2) cout<<"Yes\n";
    else cout<<"No\n";
}

int main() {
    solve();
    return 0;
}