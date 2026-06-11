#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long ll;



int main(void)
{
	int w, a, b;
	int ans;
	cin >> w >> a >> b;
	int A = a + w;
	int B = b + w;


	if (a <= b) {
		if (A >= b) {
			cout << 0;
		}
		else {
			ans = b - A;
			cout << ans;
		}
	}
	else {
		if (B >= a) {
			cout << 0;
		}
		else {
			ans = a - B;
			cout << ans;
		}
	}

	
	cout << endl;
}
