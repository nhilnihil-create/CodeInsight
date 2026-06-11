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
LL K;

string ans;

void solve(){
	int N = S.size();
	for(int i=0;i<N;i++){
		if(K==0) break;
		if('z'-S[i]+1<=K && S[i]!='a'){
			K-=('z'-S[i]+1);
			S[i] = 'a';
		}
	}
	K %= 26LL;
	if(((int)S[N-1]) + K>'z') K-=26;
	S[N-1] += K;
	ans = S;
}
 
int main(){
    cin >> S;
    cin >> K;

    solve();

	cout << ans << endl;
    return 0;
}