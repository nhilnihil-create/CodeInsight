#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<limits>
#include<list>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i < (n); ++i)



int main(){
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	int count = 0,abr = 0;
	rep(i, s.size()) {
		if (s[i] == 'a') {
			if (count < a + b) {
				cout << "Yes" << endl;
				count++;
			}
			else cout << "No" << endl;
		}
		else if (s[i] == 'b') {
			if (count < a + b && abr < b) {
				cout << "Yes" << endl;
				count++;
				abr++;
			}
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}

	return 0;
}