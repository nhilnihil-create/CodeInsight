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
#include <stack>
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

LL N;
LL A[300000];

LL ans = -INF;

void solve(){
	multiset<LL> bigger;
	LL bigger_accum = 0;

	multiset<LL> smaller;
	multiset<LL> smaller_hidden;
	LL smaller_accum = 0;

	for(int i=0;i<N;i++){
		bigger.insert(A[i]);
		bigger_accum += A[i];
	}
	for(int i=N;i<3*N;i++) smaller_hidden.insert(A[i]);

	for(int _=0;_<N;_++){
		auto iter = smaller_hidden.begin();
		smaller.insert(*iter);
		smaller_accum += (*iter);
		smaller_hidden.erase(iter);
	}

	ans = max(ans,bigger_accum-smaller_accum);
	for(int i=N;i<2*N;i++){
		//bigger更新
		bigger.insert(A[i]);
		bigger_accum += A[i]-(*(bigger.begin()));
		bigger.erase(bigger.begin());

		//smaller更新
		//smallerにA[i]が入っているなら
		if(smaller.find(A[i])!=smaller.end()){
			smaller_accum -= A[i];
			smaller.erase(smaller.find(A[i]));
			smaller_accum += (*(smaller_hidden.begin()));
			smaller.insert(*(smaller_hidden.begin()));
			smaller_hidden.erase(smaller_hidden.begin());
		}
		//smallerにA[i]が入ってないなら
		else{
			smaller_hidden.erase(smaller_hidden.find(A[i]));
		}

		ans = max(ans,bigger_accum-smaller_accum);
	}
}

int main(){
    cin >> N;
    for(int i=0;i<3*N;i++) cin >> A[i];

    solve();

    cout << ans << endl;
    return 0;
}
