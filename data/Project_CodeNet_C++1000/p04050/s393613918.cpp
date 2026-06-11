#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,M;
	cin >> N >> M;
	vector<int> A(M);
	int odd =0;
	for(int i =0; i < M; i++) {
		cin >> A[i];
		if(A[i]%2 != 0) odd++;}
	if(odd > 2) {cout << "Impossible\n"; return 0;}
	for(int i =0; i < M; i++) if(A[0]%2 == 0 && A[i]%2 != 0) swap(A[0],A[i]);
	for(int i =1; i < M; i++) if(A[M-1]%2 == 0 && A[i]%2 != 0) swap(A[M-1],A[i]);
	for(int i =0; i < M; i++) cout << A[i] << ((i == M-1)?"\n":" ");
	vector<int> B;
	if(A[0] > 1) B.push_back(A[0]-1);
	if(M > 1) B.push_back(2);
	else B.push_back(1);
	for(int i =1; i < M-1; i++) B.push_back(A[i]);
	if(M > 1 && A[M-1] > 1) B.push_back(A[M-1]-1);
	M =B.size();
	cout << M << "\n";
	for(int i =0; i < M; i++) cout << B[i] << ((i == M-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing
