#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string A, B;
	cin >> A >> B;
	if (A.size()>B.size()) {
		cout << "GREATER" << endl;
		return 0;
	}
	if (A.size()<B.size()) {
		cout << "LESS" << endl;
		return 0;
	}
	rep(i,A.size()){
		if ((A[i]-'0') > (B[i]-'0')) {
			cout << "GREATER" << endl;
			return 0;
		}
		if ((A[i]-'0') < (B[i]-'0')) {
			cout << "LESS" << endl;
			return 0;
		}
	}
	cout << "EQUAL" << endl;
	return 0;
}
