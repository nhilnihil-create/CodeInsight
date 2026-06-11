#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int main(){
    int n,t;
    cin >> n >> t;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    map<int,int>mp;
    int ma = -1;
    for(int i = n-1; i >= 0; i--){
        ma = max(ma, a[i]);
        mp[ma-a[i]]++;
    }
    int ans = 0;
    for(auto x:mp)ans = x.second;
    cout << ans << endl;
}