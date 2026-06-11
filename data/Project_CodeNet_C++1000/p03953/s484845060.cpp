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
#define int long long
int n;
int x[100005];
int dx[100005];
int a[100005];
vector<int>b;
vector<int> f(vector<int>x, ll k){
    if(k==0){
        vector<int>res(n-1);
        rep(i,n-1)res[i] = i;
        return res;
    }
    if(k==1)return x;
    auto res = f(x,k/2);
    auto res2 = res;
    if(k%2){
        rep(i,n-1){
            res2[i] = res[x[i]];
        }
    }
    vector<int>temp(n-1);
    rep(i,n-1)temp[i] = res[res2[i]];
    return temp;
}
signed main(){
    cin >> n;
    rep(i,n){
        cin >> x[i];
    }
    rep(i,n-1){
        dx[i] = x[i+1] - x[i];
//        show(dx[i]);
    }
    int m;
    ll k;
    cin >> m >> k;
    rep(i,n-1){
        b.push_back(i);
    }
    rep(i,m){
        cin >> a[i];
        a[i]--;
        swap(b[a[i]-1],b[a[i]]);
    }
    rep(i,n-1){
//        show(b[i]);
    }
    auto c = f(b,k);
    rep(i,n-1){
//        show(c[i]);
    }
    int ans = x[0];
    rep(i,n){
        cout << ans << endl;
        if(i!=n-1){
            ans += dx[c[i]];
        }
    }
}