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
#include <limits>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;

int main() {
    string s1, s2, s3, s4;
    s1 = "dream";
    s2 = "dreamer";
    s3 = "erase";
    s4 = "eraser";

    reverse(ALL(s1)); reverse(ALL(s2)); reverse(ALL(s3)); reverse(ALL(s4));

    string s; cin >> s;
    reverse(ALL(s));

    bool fg = true;
    int ind = 0;

    while (fg) {
        if (ind == s.size()) {
            break;
        }
        fg = false;
        if (s1 == s.substr(ind, 5)) {
            ind += 5;
            fg = true;
            continue;
        }
        else if (s2 == s.substr(ind, 7)) {
            ind += 7;
            fg = true;
            continue;
        }
        else if (s3 == s.substr(ind, 5)) {
            ind += 5;
            fg = true;
            continue;
        }else if (s4 == s.substr(ind, 6)) {
            ind += 6;
            fg = true;
            continue;
        }
    }

    if (ind == s.size()) {
        pYES;
    }
    else {
        pNO;
    }

}