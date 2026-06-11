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
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
LL A[100000];

LL ans = 0;

void solve(){
	LL prev_index = -INF;
	for(int i=0;i<N;i++){
		if(A[i]%2==0){
			ans += A[i]/2;
			if(prev_index!=-INF && A[i]!=0) prev_index++;
			if(prev_index!=-INF && A[i]==0) prev_index = -INF;
		}
		if(A[i]%2==1){
			ans += A[i]/2;
			if(prev_index==-INF){
				prev_index = i;
			}
			else{
				if(prev_index==i-1){
					ans++;
					prev_index = -INF;
				}
			}
		}
	}
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
 
    solve();

    cout << ans << endl;
    return 0;
}