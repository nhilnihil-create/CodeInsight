#include <bits/stdc++.h>
using namespace std;
int main(){
	int k, s, r=0;
	cin >> k>>s;
	for (int y=0; y<=k; y++){
		for (int z=0;z<=k;z++){
			int op=s-y-z;
			if (op >= 0 && op <= k) r++;
		}
	}
	cout << r;
	
	return 0;	
}