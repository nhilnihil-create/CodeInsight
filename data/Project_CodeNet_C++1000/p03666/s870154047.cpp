#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#define MP(a, b) make_pair(a, b)
#define POWER9 1000000000
#define MOD POWER9+7
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define LL_MIN (LL)-9223372036854775807
#define LL_MAX (LL)9223372036854775807
#define PI 3.14159265359

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(9);

	LL N,A,B,C,D;
	cin >> N >> A >> B >> C >> D;
	B = abs(A-B);
	A = 0;
	LL M = 0;
	LL m = 1;
	for(int i=1; i<N; i++){
		M += D;
		m += D-C;
	}
	LL tmp = abs(M-B+1);
	if(B <= M && (tmp % (D+C)==0?D+C:tmp % (D+C)) <= m) cout << "YES" << endl;
	else cout << "NO" << endl;
	//cout << M << " " << m << " " << tmp << endl;

	return 0;
}
