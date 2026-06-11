#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string A, B, C;
	cin >> A >> B >> C;
	char h = 'a';
	int i=0, j=0, k=0;
	while (1) {
		switch (h) {
			case 'a':
				h = A[i];
				i++;
				if (i == A.size()+1) {
					cout << 'A' << endl;
					return 0;
				}
				break;
			case 'b':
				h = B[j];
				j++;
				if (j == B.size()+1) {
					cout << 'B' << endl;
					return 0;
				}
				break;
			case 'c':
				h = C[k];
				k++;
				if (k == C.size()+1) {
					cout << 'C' << endl;
					return 0;
				}
				break;
		}
	}
	return 0;
}
