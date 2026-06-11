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
#define OVER9000 1234567890123456789LL
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

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,M,d;
	cin >> N >> M >> d;
	string col ="RYGB";
	vector< vector<int> > C(N,vector<int>(M,-1));
	if(d%2) {
		for(int i =0; i < N; i++) for(int j =0; j < M; j++) C[i][j] =(i+j)%4;
	}
	else {
		for(int i =0; i < N; i++) for(int j =0; j < M; j++) if(C[i][j] == -1) {
			for(int k =i-d; k < N+d; k +=d/2) for(int l =j-d; l < M+d; l +=d/2) if((k-i+l-j)%d == 0) {
				int kn =(k-i)/(d/2), ln =(l-j)/(d/2), colc;
				if(kn%2 == 0) colc =((kn+ln)/2+10)%2;
				else colc =2+((kn+ln)/2+10)%2;
				for(int a =0; a < d/2; a++) if(k+a >= 0 && k+a < N && l+a >= 0 && l+a < M) C[k+a][l+a] =colc;
				for(int a =0; a < d/2; a++) if(k+a < N && k+a >= 0 && l-a < M && l-a >= 0) C[k+a][l-a] =colc;
				for(int a =0; a < d/2; a++) if(k+d-2-a >= 0 && k+d-2-a < N && l-a < M && l-a >= 0) C[k+d-2-a][l-a] =colc;
				for(int a =0; a < d/2; a++) if(k+d-2-a >= 0 && k+d-2-a < N && l+a >= 0 && l+a < M) C[k+d-2-a][l+a] =colc;
			}
			i =N;
			break;
		}
		for(int i =0; i < N; i++) for(int j =0; j < M; j++) if(C[i][j] == -1) {
			for(int k =i-d; k < N+d; k +=d/2) for(int l =j-d; l < M+d; l +=d/2) if((k-i+l-j)%d == 0) {
				int kn =(k-i)/(d/2), ln =(l-j)/(d/2), colc;
				if(kn%2 == 0) colc =((kn+ln)/2+10)%2;
				else colc =2+((kn+ln)/2+10)%2;
				for(int a =0; a < d/2; a++) if(k+a >= 0 && k+a < N && l+a >= 0 && l+a < M) C[k+a][l+a] =colc;
				for(int a =0; a < d/2; a++) if(k+a < N && k+a >= 0 && l-a < M && l-a >= 0) C[k+a][l-a] =colc;
				for(int a =0; a < d/2; a++) if(k+d-2-a >= 0 && k+d-2-a < N && l-a < M && l-a >= 0) C[k+d-2-a][l-a] =colc;
				for(int a =0; a < d/2; a++) if(k+d-2-a >= 0 && k+d-2-a < N && l+a >= 0 && l+a < M) C[k+d-2-a][l+a] =colc;
			}
			i =N;
			break;
		}
		for(int i =0; i < N; i++) for(int j =0; j < M; j++) if(C[i][j] == -1) {
			if(i > 0 && C[i-1][j] != -1) C[i][j] =C[i-1][j];
			if(j > 0 && C[i][j-1] != -1) C[i][j] =C[i][j-1];
		}
	}
	for(int i =0; i < N; i++) {
		string s;
		for(int j =0; j < M; j++) s +=col[C[i][j]];
		cout << s << "\n";
	}
	return 0;}

// look at my code
// my code is amazing
