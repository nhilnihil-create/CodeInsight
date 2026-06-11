#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const int MOD = 1000000007;
using namespace std;

int main(){
    int h, w, n; cin >> h >> w >> n;
    vector<vector<int>> c(h, vector<int>(w));
    int cnt=0;
    REP(i, n){
        int a; cin >> a;
        REP(j, a){
            int hh = cnt / w;
            int ww = cnt % w;
            if(hh%2) ww = w - ww - 1;
            c[hh][ww] = i+1;
            ++cnt;
        }
    }
    REP(i, h){
        REP(j, w){
            if(j) cout << " ";
            cout << c[i][j];
        }
        cout << "\n";
    }
    return 0;
}