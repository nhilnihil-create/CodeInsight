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

bool check( int biti , int x){
    bool ok = true;
    while(x > 0) {
        if(( biti >> (x % 10) ) & 1) ok = false;
        x /= 10;
    }
    return ok;
}

int main(){
    int n , k, var;
    cin >> n >>k;
    int bit = 0;
    rep(i , k) {
        cin >> var;
        bit += ( 1 << var);
    }
    // inside bit if 1, unusable
   for ( int i = n ; i < 100 * n ; i++){
       if (check( bit , i ) ){
           cout << i << endl;
           return 0;
       }
       else
           continue;
   }

}