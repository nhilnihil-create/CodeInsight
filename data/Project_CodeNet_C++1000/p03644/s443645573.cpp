#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
	int n;
	cin >> n;
	int ans;
	for(int i = 1;; i *= 2){
		if(i > n){
			break;
		}
		ans = i;
	}
	
	cout << ans << endl;
}