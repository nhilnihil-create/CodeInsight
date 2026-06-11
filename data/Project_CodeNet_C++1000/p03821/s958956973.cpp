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
#define ll_INF 	9223372036854775807
#define MOD 100000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
using namespace std;

int main() {
    int N; cin >> N;
    vll A(N), B(N);
    rep(i, N) {
        cin >> A[N-1-i] >> B[N-1-i];
    }

    vll dp(N); 
    if (A[0] % B[0] == 0) {
        dp[0] = 0;
    }
    else {
        dp[0] = B[0] - (A[0] % B[0]);
    }

    for (int i = 1; i < N; i++) {
        if ( ((A[i] + dp[i - 1]) % B[i]) == 0) {
            dp[i] = dp[i - 1];
        }
        else {
            dp[i] = dp[i - 1] + B[i] - ((A[i] + dp[i - 1]) % B[i]);
        }

    }

    cout << dp[N - 1] << endl;
}
