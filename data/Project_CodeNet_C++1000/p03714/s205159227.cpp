#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
#include <array>
#include <numeric>
#include <regex>
#include <bitset>
#include <deque>
#include <cassert>

using namespace std;
typedef long long ll;
typedef pair<int, int> p_ii;

const int INF = 1e9;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << ": " << x << endl;
#define popcnt __builtin_popcount


int main() {
    int N; cin>>N;
    vector<int>a(3*N);
    for (int i = 0; i < 3*N; i++) {
        cin>>a[i];
    }

    ll psum=0, ssum=0;
    priority_queue<int , vector<int>, greater<int>> pre;
    priority_queue<int> suf;

    for (int i = 0; i < N; i++) {
        psum+=a[i];
        ssum+=a[3*N-1-i];
        pre.push(a[i]);
        suf.push(a[3*N-1-i]);
    }

    vector<ll> pret, sret;
    pret.push_back(psum);
    sret.push_back(ssum);

    for (int i = N; i < 2*N; i++) {
        //前半部分
        int pt = a[i];
        pre.push(pt);
        psum+=pt;
        psum-=pre.top();
        pre.pop();
        pret.push_back(psum);
    }
    
    for (int i = 2*N-1; i >= N; i--) {
        //後半部分
        int rt = a[i];
        suf.push(rt);
        ssum+=rt;
        ssum-=suf.top();
        suf.pop();
        sret.push_back(ssum);
    }
    reverse(all(sret));
    
    ll res = (ll)-1e15;
    for (int i = 0; i <= N; i++) {
        res=max(res, pret[i]-sret[i]);
    }

    cout<<res<<endl;

    return 0;
}