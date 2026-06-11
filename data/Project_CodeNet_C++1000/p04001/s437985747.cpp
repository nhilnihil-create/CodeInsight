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
#include <numeric> // next_parmutation
#define ll long long
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int main() {
    string s;
    cin >> s;
    ll ans = 0;
    int size = s.size();

    rep(bit, (1 << size - 1)){
        string str = "";
        rep(i,size){
            str += s.at(i);
            if(bit >> i&1){
                ans += stoll(str);
                str = "";
            }
        }
        ans += stoll(str);
        str = "";
    }

    cout << ans << endl;
    return 0;
}