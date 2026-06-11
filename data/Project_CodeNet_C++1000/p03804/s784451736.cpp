#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007

using namespace std;
using ll = long long;
using ldb = long double;

bool check(vector<string>& A, vector<string>& B,int a,int b) {
	int N = A.size(), M = B.size();
	if (a + M - 1 >= N || b + M - 1 >= N) return false;	
	bool res = true;
	for (int i = 0; i < M&&res; i++) {
		for (int j = 0; j < M; j++) {		
			if (A[a + i][b + j] != B[i][j]) {
				res = false;
				break;
			}
		}
	}
	return res;
}
int main() {
	int N, M; cin >> N >> M;
	vector<string> A(N), B(M);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
		}
	}
	for (int i = 0; i < N && !flag; i++) {
		for (int j = 0; j < N; j++) {
			if (check(A, B, i, j)) {
				flag = true;
				break;
			}
		}
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}
