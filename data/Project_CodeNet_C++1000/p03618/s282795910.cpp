#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string a; cin >> a;

    map<char, ll> mp;
    rep(i, a.size()){
        mp[a[i]]++;
    }

    ll d = 0;
    for(auto e : mp){
        ll num = e.second;
        if(num >= 2){
            d += num * (num-1) / 2;
        }
    }

    cout << a.size() * (a.size() - 1) / 2 - d + 1 << endl;

    return 0;
}