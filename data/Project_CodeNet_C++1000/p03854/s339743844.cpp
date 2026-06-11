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

    string s; cin >> s;

    bool hantei = true;

    while(s.size() > 0){
        int n = s.size();
        if(n >= 5 && s.substr(n-5,5) == "dream"){
            for(int i = 0;i < 5;i ++) s.pop_back();
            continue;
        }
        if(n >= 7 && s.substr(n-7,7) == "dreamer"){
            for(int i = 0;i < 7;i ++) s.pop_back();
            continue;
        }
        if(n >= 5 && s.substr(n-5,5) == "erase"){
            for(int i = 0;i < 5;i ++) s.pop_back();
            continue;
        }
        if(n >= 6 && s.substr(n-6,6) == "eraser"){
            for(int i = 0;i < 6;i ++) s.pop_back();
            continue;
        }

        hantei = false;
        break;

    }

    if(hantei) cout << "YES" << endl;
    else cout << "NO" << endl;
}