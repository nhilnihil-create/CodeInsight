#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))

typedef long long ll;

int main(){
    int n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    priority_queue<pair<ll,int>> pq;
    vector<ll> r(n), l(n);
    rep(i,n){
        if(!pq.empty()){
            while(!pq.empty() && pq.top().first > a[i]){
                int id = pq.top().second; 
                pq.pop();
                r[id] = i;
            }
        }
        pq.push(mp(a[i], i));
    }
    while(!pq.empty()){
        int id = pq.top().second;
        r[id] = n;
        pq.pop();
    }
    
    for(int i=n-1;i>=0;i--){
        if(!pq.empty()){
            while(!pq.empty() && pq.top().first > a[i]){
                int id = pq.top().second;
                pq.pop();
                l[id] = i;
            }
        }
        pq.push(mp(a[i], i));
    }
    while(!pq.empty()){
        int id = pq.top().second;
        l[id] = -1;
        pq.pop();
    }
/*
    rep(i,n) cout << a[i] << " "; cout << endl;
    rep(i,n) cout << r[i] << " "; cout << endl;
    rep(i,n) cout << l[i] << " "; cout << endl;
*/
    ll ans = 0;
    rep(i,n) {
        ans = ans + (a[i] * (r[i] - i) * (i - l[i]));
    }
    cout << ans << endl;
    return 0;
}