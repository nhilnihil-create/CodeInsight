#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};


int main() {
    int n,m; cin >> n >> m;
    vector<pair<int,int>> mp[n];
    vector<int> a(n),b(n),c(m),d(m);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,m) cin >> c[i] >> d[i];

    rep(i,n) rep(j,m){
        mp[i].push_back(make_pair(abs(a[i]-c[j])+abs(b[i]-d[j]),j));
    }
    rep(i,n){
        sort(mp[i].begin(),mp[i].end());
    }
    rep(i,n) cout << mp[i][0].second + 1 << endl;

}
