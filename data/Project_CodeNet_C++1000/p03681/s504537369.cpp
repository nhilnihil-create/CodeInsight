//(・ω・)
#include <stdio.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, atoi
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
#include <iomanip> //setprecision
#include <limits>
#include <sstream> //istringstream
#include <stdlib.h>
#include <list>
#include <iterator>//std::advance()
using namespace std;

int main(){
    const long long mod=1000000007;
    long long n,m,ans=1;
    cin >> n >> m;
    if(abs(n-m)>1) cout << 0 << endl;
    else{
        for(long long i=1; i<=max(m,n); i++){
            ans*=i;
            ans%=mod;
            if(i<=min(m,n)){
                ans*=i;
                ans%=mod;
            }
        }
        if(m==n){
            ans*=2;
            ans%=mod;
        }
        cout << ans << endl;
    }
}
