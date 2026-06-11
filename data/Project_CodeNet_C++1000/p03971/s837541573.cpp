#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;

int main(){
	int N, A, B;
	cin >> N >> A >> B;
	string S;
	cin >> S;
	vector<bool> isOK(N);
	int allcnt = 0, bcnt= 0;
	rep(i,N) {
		if(S[i] == 'a'){
			if(allcnt < A + B){
				cout << "Yes" << endl;
				allcnt++;
			}
			else cout << "No" << endl;
		}
		else if(S[i] == 'b') {
			if(allcnt < A+ B && bcnt < B) {
				cout << "Yes" << endl;
				allcnt++;
				bcnt++;
			}
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}
	return 0;



}








