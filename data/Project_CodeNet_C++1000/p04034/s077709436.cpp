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

    ll n, m; cin >> n >> m;
    ll x[m], y[m];
    rep(i, m){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }

    ll red[n] = {};
    red[0] = 1;

    ll ball[n] = {};
    rep(i, n){
        ball[i] = 1;
    }

    rep(i, m){
        ll from = x[i];
        ll to = y[i];
        if(red[from] == 0){
            ball[from]--;
            ball[to]++;
        }
        else{
            if(ball[from] == 1){
                red[from] = 0;
                red[to] = 1;
                ball[from] = 0;
                ball[to]++;
            }
            else{
                red[to] = 1;
                ball[from]--;
                ball[to]++;
            }
        }
    }

    cout << accumulate(red, red + n, 0LL) << endl;

    return 0;
}