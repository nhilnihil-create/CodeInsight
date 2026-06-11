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
#include<cmath>
#include<limits>
#define ll long long
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
using namespace std;

vi generate(vi& vec) {
    vector<int> res;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i]; j++) {
            res.push_back(i + 1);
        }
    }
    return res;
}

int main() {
    int H, W, N; cin >> H >> W >> N;
    vi vec(N); rep(i, N) cin >> vec[i];
    vi gen = generate(vec);

    int dir = 1;
    int cnt = 0;
    vector<vi> ans(H, vi(W));
    for (int i = 0; i < H; i++) {
        if (dir < 0) {
            int j = W - 1;
            for (; j >= 0; j--) {
                ans[i][j] = gen[cnt];
                cnt++;
            }
            dir = -dir;
        }
        else {
            int j = 0;
            for (; j < W; j++) {
                ans[i][j] = gen[cnt];
                cnt++;
            }
            dir = -dir;
        }
    }

    for (auto v : ans) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    cout << endl;
}