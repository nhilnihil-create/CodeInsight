#include <iostream>
#include <stdio.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <bitset>
#include <stack>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
using namespace std;


int main(void)
{
	int N; cin >> N;
	vector<int> T(N), A(N); rep(i, 0, N)cin >> T[i] >> A[i];
	lli Takahashi = 1, Aoki = 1;
	rep(i, 0, N) {
		lli t = (T[i] + Takahashi - 1) / T[i];
		lli a = (A[i] + Aoki - 1) / A[i];
		Takahashi = T[i] * ((t > a) ? t : a);
		Aoki = A[i] * ((t > a) ? t : a);
	}
	cout << (Takahashi + Aoki) << endl;
	
	return 0;
}