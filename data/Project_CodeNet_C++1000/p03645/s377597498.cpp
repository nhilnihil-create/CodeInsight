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
    vector<int> a(m),b(m);
    for(int i = 0;i < m;i ++) cin >> a.at(i) >> b.at(i);
    vector<int> s(0),g(0);
    for(int i = 0;i < m;i ++){
        if(a.at(i) == 1) s.push_back(b.at(i));
        else if(b.at(i) == 1) s.push_back(a.at(i));
        else if(a.at(i) == n) g.push_back(b.at(i));
        else if(b.at(i) == n) g.push_back(a.at(i));
    }
    if(s.size() == 0 || g.size() == 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    sort(s.begin(),s.end());
    sort(g.begin(),g.end());


    for(int i = 0;i < s.size();i ++){
        if(lower_bound(g.begin(),g.end(),s.at(i)) != upper_bound(g.begin(),g.end(),s.at(i))){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;

}