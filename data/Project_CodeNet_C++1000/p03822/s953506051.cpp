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
vector<int>g[123456];
int dfs(int s,int p){
    int res = 0;
    vector<int>a;
    for(int x:g[s]){
        if(x != p){
            a.push_back(dfs(x,s));
        }
    }
    sort(a.rbegin(),a.rend());
    int cnt = 1;
    for(int x:a){
        res = max(res, x + cnt);
        cnt++;
    }
//    cerr << s + 1 << " " << res << endl;
    return res;
}
int main(){
    int n;
    cin >> n;
    rep(i,n-1){
        int a;
        cin >> a;
        a--;
        g[a].push_back(i+1);
        g[i+1].push_back(a);
    }
    cout << dfs(0,-1) << endl;
}