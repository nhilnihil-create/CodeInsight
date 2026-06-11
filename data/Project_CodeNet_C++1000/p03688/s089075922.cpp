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
LL A[100000];

string ans = "No";

void solve(){
	sort(A,A+N,greater<LL>());
	set<LL> nums;//登場した番号を格納
	map<LL,LL> counter;//番号iが何回登場したかをcounter[i]とする
	for(int i=0;i<N;i++){
		nums.insert(A[i]);
		counter[A[i]]++;
	}
	if(nums.size()==1){
		LL num = *(nums.begin());
		if(num*2<=N || num==N-1){
			ans = "Yes";
			return;
		}
	}
	if(nums.size()>=3) return;

	LL miner = *(nums.begin());
	LL larger = *(++nums.begin());
	if(miner!=larger-1) return;
	if(counter[larger]>=2*(larger-counter[miner]) && larger-counter[miner]>0) ans = "Yes";
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];

    solve();

	cout << ans << endl;
    return 0;
}