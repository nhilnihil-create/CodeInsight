#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <climits>

using namespace std;

int main(){
    int n; cin >> n;
    unordered_map<int, int> mp;
    for(int i=0; i<n; ++i){
        int a; cin >> a;
        ++mp[a];
    }
    int num_even=0, num_odd=0;
    for(auto& p : mp){
        if(p.second%2) ++num_odd;
        else ++num_even;
    }
    cout << num_odd+num_even-num_even%2 << endl;
    return 0;
}
