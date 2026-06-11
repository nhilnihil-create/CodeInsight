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
#define rep(i , n) for (int i = 1; i <= (int)(n); i++)
#define repz(i , n) for (int i = 0; i < (int) n; i++)
#define repi(i , r, n) for (int i = r; i <= (int)(n); i++)
#define repd(i , r, n) for (int i = r; i >= (int)(n); i--)


using namespace std;


int main(){
    int n, m , a, b;
    cin >> n >> m;
    int amount[n+1];
    rep( i , n) amount[i] = 1;
    bool red[n+1];
    red[1] = true;
    rep(i , m){
        cin >> a >> b;
        amount[a]--;
        amount[b]++;
        if ( red[a]) red[b] = true;
        if ( amount[a] == 0) red[a] = false;
        
        
    }
    int ans = 0;
    rep( i , n){
        if ( red[i] ) ans++;
    }
    
    cout << ans << endl;
    
    
}
