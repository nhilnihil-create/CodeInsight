#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll a, b;
	cin >> a >> b;
	int f = 100;
	if (a<=0) {
		if (b>=0) f = 0;
		else {
			if ((b-a)%2 == 1) f = 1;
			else f = -1;

			if (b==a) f = 1;
		}
	}
	else f = 1;

	switch (f) {
		case 1:
			cout << "Positive" << endl;
			break;
		case -1:
			cout << "Negative" << endl;
			break;
		case 0:
			cout << "Zero" << endl;
			break;
	}
	return 0;
}
