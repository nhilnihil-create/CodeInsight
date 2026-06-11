#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, m; 
	cin >> n >> m;
	vector<int> v(m);
	for(int i = 0; i < m; ++i)
		cin >> v[i];
	bool found = false;
	while(!found){
		int tempN = n;
		bool notTheOne = false;
		while(tempN != 0 && !notTheOne){
			for(int i : v){
				if(tempN%10 == i){
					notTheOne = true;
					break;
				}
			}
			tempN /= 10;
		}
		if(notTheOne){
			++n;
			continue;
		}
		found = true;
	}
	cout << n;
		


	return 0;
}
