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

string S;

LL ans = INF;

void solve(){
	int N = S.size();
	for(char al='a';al<='z';al++){
		LL counter = 0;
		for(int i=0;i<N;){
			int j=i;
			while(S[j]!=al && j<N) j++;
			counter = max(counter,(LL)(j-i));
			i = j+1;
		}
		ans = min(ans,counter);
	}
}
 
int main(){
    cin >> S;
 
    solve();

	cout << ans << endl;
    return 0;
}