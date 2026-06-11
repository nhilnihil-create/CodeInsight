#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <math.h>
#include <assert.h>
#include <set>
#include <map>
#include <bitset>
#include <ctime>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <stack>
#include <ctype.h>
#include <numeric>
#include <sstream>
#include <unistd.h>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;
/*mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());*/
using ll = long long;
#define endl '\n'
#define debug(name) DEBUG(#name, (name))
template<typename T>
void DEBUG(string label, T value) {
    cerr << "[" << label << " = " << value << "]\n";
}
void solve(){
    string s;
    cin >> s;
    int n = (int)s.size();
    ll ans = 0;
    for(int i = 0; i < (1 << (n - 1)); ++i){
        vector<int> pos = {-1};
        for(int j = 0; j < n - 1; ++j){
            if(i & (1 << j)){
                pos.push_back(j);
            }
        }
        pos.push_back(n - 1);
        for(int j = 0; j < (int)pos.size() - 1; ++j){
            ll cur = 0;
            ll t = 1;
            for(int k = pos[j + 1]; k > pos[j]; --k){
                cur += t * (s[k] - '0');
                t *= 1LL * 10;
            }
            ans += cur;
        }
    }
    cout << ans << endl;

}

int main(){
    /*ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);*/

    int t;
    t = 1;
    int test = 0;
    while(t--){
        /*cout << "Case " << ++test << ": ";*/
        solve();
    }

}
