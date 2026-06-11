#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int odd = 0;
	int even = 0;
	for(int i = 0; i< n; i++){
		int x;
		cin >> x;
		if(x%2 == 0) even++;
		if(x%2 == 1) odd++;
	}
	if(odd % 2 == 0) cout << "YES" << endl;
	if(odd % 2 == 1) cout << "NO" << endl;
}
