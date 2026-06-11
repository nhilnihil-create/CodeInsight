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

    int n; cin >> n;
    vector<int> a(n);

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    for(int i = 0;i < n;i ++) cin >> a.at(i);

    int ans = 1;

    int hantei;
    if(a.at(1) - a.at(0) > 0) hantei = 2;
    else if(a.at(1) - a.at(0) == 0) hantei = 1;
    else hantei = 0;

    for(int i = 1;i < n-1;i ++){
        if(a.at(i) - a.at(i-1) > 0) hantei = 2;
        else if(a.at(i)- a.at(i-1) < 0)hantei = 0;

        if(hantei == 2 && a.at(i+1) - a.at(i) < 0){
            ans ++;
            i ++;
            hantei = 1;
        }
        else if(hantei == 0 && a.at(i+1) - a.at(i) > 0){
            ans ++;
            i ++;
            hantei = 1;
        }
        else if(hantei == 1){
            if(a.at(i+1) - a.at(i) > 0) hantei = 2;
            if(a.at(i+1) - a.at(i) < 0) hantei = 0;
        }
    }

    cout << ans << endl;
}

