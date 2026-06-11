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
#include <math.h> // sqrt
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    vector<string> ans(N, "No");
    int pass = 0;
    int brank = 0;
    for (int i = 0; i < N; i++) {
        if (A + B <= pass) {
            break;
        }
        if (S.at(i) == 'a') {
            pass++;
            ans.at(i) = "Yes";
            continue;
        }
        if (S.at(i) == 'b') {
            brank++;
            if (brank <= B) {
                pass++;
                ans.at(i) = "Yes";
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }
}