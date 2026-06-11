#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string S, T;
	cin >> S >> T;
	int N, M;
	N = S.size();
	M = T.size();
	int ok = 2;
	if(N > M) ok = 0;
	else if (N < M) ok = 1;
	else{
		rep(i,N){
			int a, b;
			a = S[i] - '0';
			b = T[i] - '0';
			if(a > b) {
				ok = 0;
				break;
			}
			else if(a < b){
			    ok = 1;
				break;
			}
		}
	}
	if(ok == 0) cout << "GREATER" << endl;
	else if(ok == 1) cout << "LESS" << endl;
	else cout << "EQUAL" << endl;
}











