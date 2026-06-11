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

    int n,c,k; cin >> n >> c >> k;
    vector<int> t(n);
    for(int i = 0;i < n;i ++) cin >> t.at(i);

    sort(t.begin(),t.end());
    int ans = 0;
    int saisyo = t.at(0);
    int ninzu = 0;

    for(int i = 0;i < n;i ++){
        if(ninzu < c && t.at(i) - saisyo <= k){
            ninzu ++;
            continue;
        }
        else{
            ans ++;
            ninzu = 1;
            saisyo = t.at(i);
            continue;
        }
    }

    cout << ans + 1 << endl;

}