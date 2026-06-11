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

LL N,L;
LL A[100000];

string ans = "Impossible";
vector<LL> order;

void solve(){
	int bound = -1;
	for(int i=0;i<=N-2;i++){
		if(A[i]+A[i+1]>=L){
			bound = i+1;
			ans = "Possible";
			break;
		}
	}
	if(bound==-1) return;
	for(int i=1;i<bound;i++) order.push_back(i);
	for(int i=N-1;i>=bound;i--) order.push_back(i);
}

int main(){
    cin >> N >> L;
    for(int i=0;i<N;i++) cin >> A[i];

    solve();

	cout << ans << endl;
	for(int i=0;i<order.size();i++) cout << order[i] << endl;
    return 0;
}