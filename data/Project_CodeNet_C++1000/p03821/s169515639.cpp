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
#define rep(i , n) for (int i = 1; i <= (int)(n); i++)
#define repz(i , n) for (int i = 0; i < (int) n; i++)
#define repi(i , r, n) for (int i = r; i <= (int)(n); i++)
#define repd(i , r, n) for (int i = r; i >= (int)(n); i--)

using namespace std;

int64_t calc( int64_t a , int64_t b){
    if ( b % a == 0) return 0;
    else
        return (b / a + 1) * a - b;
}

int main(){
    int n;
    cin >> n;
    int64_t a[n];
    int64_t b[n];
    repz(i , n){
        cin >> a[i] >> b[i];
    }
    int64_t ans = 0;
    repd(i , n - 1 , 0){
        ans += calc( b[i] , a[i] + ans);
    }
    cout << ans << endl;
    
}