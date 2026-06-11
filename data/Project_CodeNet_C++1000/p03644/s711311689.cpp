#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N;
	cin >> N;
	int cmax = 0, Nmax = 1;
	for (int i = 1; i <= N; i++) {
		int c = 0;
		int t = i;
		while (t%2 == 0){
			c++;
			t /= 2;	
		}
		if (c > cmax){
			cmax = c;
			Nmax = i;
		}	
	}
	cout << Nmax << endl;
	return 0;
}
