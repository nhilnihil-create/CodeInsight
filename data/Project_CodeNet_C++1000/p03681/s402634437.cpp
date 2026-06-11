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

    int n,m; cin >> n >> m;

    if(abs(n-m) > 1){
        cout << 0 << endl;
        return 0;
    }

    int nkumi = 1,mkumi = 1;

    for(int i = n;i > 0;i --){
        nkumi *= i;
        nkumi %= 1000000007;
    }
    for(int i = m;i > 0;i --){
        mkumi *= i;
        mkumi %= 1000000007;
    }

    
    int ans = nkumi * mkumi;
    ans %= 1000000007;

    if(n == m){
        ans *= 2;
        ans %= 1000000007;
    }

    cout << ans << endl;
}