#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using namespace std;
using vi = vector<int64_t>;
using vvi = vector<vi>;

int main(int argc, const char * argv[]) {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t n,time;
    cin >> n >> time;
    vector<int64_t> t(n);
    rep(i,n) cin >> t.at(i);
    int64_t dt, res=0;
    rep(i,n-1){
        dt = t.at(i+1) - t.at(i);
        if(dt <= time){
            res += dt;
        }else{
            res += time;
        }
    }
    res += time;
    cout << res << endl;
}
