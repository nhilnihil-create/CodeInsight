#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
 
int main(){
    ll N,T;
    cin >> N >> T;
    ll m = LLONG_MAX;
    ll val_max = LLONG_MIN;
    vector<ll> mm;
    REP(i,N){
        ll a;
        cin >> a;
        ll val = max(0LL, a - m);
        if(val_max < val){
            val_max = val;
            mm.clear();
            mm.push_back(m);
        }else if(val_max == val){
            mm.push_back(m);
        }
        m = min(m, a);
    }

    sort(mm.begin(), mm.end());
    ll num = -1;
    ll ans = 0;
    REP(i,mm.size()){
        //printf("min:%d\n", mm[i]);
        if(num != mm[i]) ans++;
        num = mm[i];
    }
    cout << ans << endl;
    return 0;
}
