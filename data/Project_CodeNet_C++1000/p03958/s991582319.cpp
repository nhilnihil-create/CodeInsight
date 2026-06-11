#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip>
using namespace std;
#define int long long

signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int k,t; cin >> k >> t;
    vector<int> a(t);
    for(int i = 0;i < t;i ++) cin >> a.at(i);

    sort(a.begin(),a.end());
    int m = a.at(t-1);

    int ans;
    if(m <= (k+1)/2) ans = 0;
    else ans = (m- (k+1)/2) * 2;

    if(ans > 0) ans -= (k+1) % 2;

    cout << ans << endl;

}