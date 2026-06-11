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
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,A,B,C,D;

string ans = "YES";

void solve(){
    N--;
    if(A>B) swap(A,B);
    LL lower = -N*D;
    LL upper = -N*C;
    for(int _=0;_<N+1;_++){
        //cout << lower << " " << upper << endl;
        if(lower<=(B-A) && (B-A)<=upper) return;
        lower += C+D;
        upper += C+D;
    }
    ans = "NO";
}

int main(){
    cin >> N >> A >> B >> C >> D;

    solve();

	cout << ans << endl;
    return 0;
}