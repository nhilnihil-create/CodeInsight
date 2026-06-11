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


signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    vector<vector<int> > ncr(51,vector<int> (51));

    for(int i = 0;i < 51;i ++){
        ncr.at(i).at(0) = 1;
    }

    for(int i = 1;i < 51;i ++){
        for(int j = 1;j < 51;j ++){
            ncr.at(i).at(j) = ncr.at(i-1).at(j-1) + ncr.at(i-1).at(j);
        }
    }

    int n,p; cin >> n >> p;
    vector<int> a(n);
    for(int i = 0;i < n;i ++) cin >> a.at(i);

    int gusu = 0, kisu = 0;
    for(int i = 0;i < n;i ++){
        if(a.at(i) % 2 == 0) gusu ++;
        else kisu ++;
    }

    int ans = 0;
    for(int i = 0;i + p <= kisu;i += 2){
        for(int j = 0;j <= gusu;j ++){
            ans += ncr.at(kisu).at(i+p) * ncr.at(gusu).at(j);
        }
    }

    cout << ans << endl;
}