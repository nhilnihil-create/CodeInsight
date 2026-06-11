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

LL N,X;

string ans = "No";
vector<LL> param;

void solve(){
	if(X==1 || X==2*N-1) return;
	ans = "Yes";
	param = vector<LL>(2*N-1,0);
	for(int i=0;i<param.size();i++){
		param[i] = i+1;
	}
	swap(param[N-1],param[X-1]);
	swap(param[N-2],param[0]);
	swap(param[N],param[2*N-2]);
}

int main(){
    cin >> N >> X;

    solve();

    cout << ans << endl;
    if(ans=="No") return 0;
    for(int i=0;i<param.size();i++) cout << param[i] << endl;
    return 0;
}