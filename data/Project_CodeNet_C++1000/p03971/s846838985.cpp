#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N, A, B;
	cin >> N >> A >> B;
	string S;
	cin >> S;
	int Nj = 0, Nf = 0;
	rep(i,N){
		if (S[i] == 'c'){
			cout << "No" << endl;
		}
		else if (S[i] == 'a'){
			if (Nj+Nf < A+B) {
				cout << "Yes" << endl;
				Nj++;
			}
			else cout << "No" << endl;
		}
		else {
			if (Nj+Nf < A+B && Nf < B){
				cout << "Yes" << endl;
				Nf++;
			}
			else cout << "No" << endl;
		}
	}
	return 0;
}
