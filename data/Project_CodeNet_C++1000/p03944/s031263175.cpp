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
#include <math.h>
#include <iomanip>
using namespace std;
#define int long long

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}


signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int w,h,n; cin >> w >> h >> n;
    vector<int> x(n),y(n),a(n);
    for(int i = 0;i < n;i ++) cin >> x.at(i) >> y.at(i) >> a.at(i);

    int xl = 0,xr = w,yu = h,yd = 0;

    for(int i = 0;i < n;i ++){
        if(a.at(i) == 1) xl = max(xl,x.at(i));
        if(a.at(i) == 2) xr = min(xr,x.at(i));
        if(a.at(i) == 3) yd = max(yd,y.at(i));
        if(a.at(i) == 4) yu = min(yu,y.at(i));
    }

    int bns = max(xr - xl,(int)0);
    int cns = max(yu - yd,(int)0);

    cout << bns * cns << endl;
}