#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int ans = 0;
	int i;
	for(i = 1; i <= n; ++i){
		if((i*i+i)/2 > n)break;
	}
	int wo = (i*i+i)/2-n;
	for(int j = 1; j <= i; ++j){
		if(j == wo)continue;
		cout << j << endl;
	}

	return 0;
}
