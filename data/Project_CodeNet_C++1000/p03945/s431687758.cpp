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
#include <cmath>
#include <math.h> // sqrt()
#include <iomanip>
#define rep(i , n) for (int i = 1; i < (int)(n); i++)

using namespace std;

int main() {
    string str;
    int sum = 0;
    char gucci;
    cin >> str;
    gucci = str.at(0);
    rep(i , str.size()){
        if ( gucci != str.at(i)){
            sum++;
            gucci = str.at(i);
        }
    }
    cout << sum << endl;
}