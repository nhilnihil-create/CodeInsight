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
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i, s, n) for(int i = s; i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
typedef long long ll;
const int MOD = 1000000007;
using namespace std;


int main(){
    int n, cnt = 0; cin >> n;
    vector<int> p(n);
    REP(i, n) cin >> p[i];
    REP(i, n-1){
        if(p[i] == i+1){
            swap(p[i], p[i+1]); ++cnt;
        }
    }
    if(p[n-1] == n) ++cnt;
    cout << cnt << "\n";
    return 0;
}
