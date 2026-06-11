#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;
	int n=0, s=0, w=0, e=0;
	rep(i,S.size()){
		switch (S[i]) {
			case 'N':
				n++;
				break;
			case 'S':
				s++;
				break;
			case 'W':
				w++;
				break;
			case 'E':
				e++;
				break;
		}
	}

	if ((n!=0 && s==0) || (n==0 && s!=0)) {
		cout << "No" << endl;
	}
	else if ((w!=0 && e==0) || (w==0 && e!=0)) {
		cout << "No" << endl;
	}
	else cout << "Yes" << endl;

	return 0;
}
