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

    int n,m; cin >> n >> m;
    vector<int> x(m),y(m);
    for(int i = 0;i < m;i ++) cin >> x.at(i) >> y.at(i);

    vector<int> a(n+1);
    a.at(1) = 1;

    vector<int> kosu(n+1,1);
    kosu.at(0) = 0;

    for(int i = 0;i < m;i ++){
        if(kosu.at(x.at(i)) > 1){
            if(a.at(x.at(i)) == 1) a.at(y.at(i)) = 1;
            kosu.at(x.at(i)) --;
            kosu.at(y.at(i)) ++;
        }else{
            kosu.at(x.at(i)) --;
            kosu.at(y.at(i)) ++;
            if(a.at(x.at(i)) == 1){
                a.at(x.at(i)) = 0;
                a.at(y.at(i)) = 1;
            }

        }
    }

    int ans = 0;
    for(int i = 1;i < n+1;i ++) ans += a.at(i);

    cout << ans << endl;
}