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
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};

ll MOD = 998244353;


int main() {
    int n; cin >> n;
    map<ll,int> mp;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) mp[a[i]]++;

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    int cnt = 0;
    rep(i,a.size()){
        if(mp[a[i]] % 2 != 0) cnt++;
        //cout << "mp[" << a[i] << "]=" << mp[a[i]] << endl;
    }
    cout << cnt << endl;


}
