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
    long long q,h,s,d;
    cin >> q >> h >> s >> d;
    long long n;
    cin >> n;
    long long ans=0;
    long long a,b,c;
    a=8*q;
    b=4*h;
    c=2*s;
    ans+=(n/2)*min(a,min(b,min(c,d)));
    if(n%2==1){
        ans+=min(q*4,min(h*2,s));
    }
    cout << ans <<endl;

}
