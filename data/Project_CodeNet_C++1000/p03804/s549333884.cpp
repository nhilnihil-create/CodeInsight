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
    vector<string> a(n),b(m);
    for(int i = 0;i < n;i ++) cin >> a.at(i);
    for(int i = 0;i < m;i ++) cin >> b.at(i);

    for(int i = 0;i < n-m+1;i ++){
        for(int j = 0;j < n-m+1;j ++){
            int hantei = 1;
            for(int k = 0;k < m;k ++){
                for(int l = 0;l < m;l ++){
                    if(b.at(k).at(l) != a.at(i+k).at(j+l)) hantei = 0;
                }
            }
            if(hantei == 1){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}