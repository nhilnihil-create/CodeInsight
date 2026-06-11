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
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll ans = 0;
    ans += a[0]-1;
    ll hoge = 2;
    int pos = 1;
    while(pos < n){
        if(a[pos] < hoge){
            pos++;
        }else if(a[pos] == hoge){
            hoge++;
            pos++;
        }else if(a[pos] > hoge){
            ans += (a[pos]-1)/hoge;
            pos++;
        }
    }
    cout << ans << endl;
}