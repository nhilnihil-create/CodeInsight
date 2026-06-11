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

LL N;
LL P[20001];

LL A[20001],B[20001];

void solve(){
	for(int i=1;i<=N;i++){
		A[i] = (i-1)*20001 + 1;
	}
	for(LL i=N;i>=1;i--){
		B[P[i]] = (1000000000LL-(N-i+1LL)) - A[P[i]];
	}
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> P[i];

    solve();

    for(int i=1;i<=N;i++) cout << A[i] << " ";
    cout << endl;
    for(int i=1;i<=N;i++) cout << B[i] << " ";
    cout << endl;
    return 0;
}