//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL K,T;
LL A[100];

LL ans = 0;

void solve(){
	sort(A,A+T,greater<LL>());
	ans = max(0LL,K-2*(K-A[0])-1);
}

int main(){
    cin >> K >> T;
    for(int i=0;i<T;i++) cin >> A[i];
 
    solve();

    cout << ans << endl;
    return 0;
}