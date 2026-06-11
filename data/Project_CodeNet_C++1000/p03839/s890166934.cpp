#include <bits/stdc++.h>

using namespace std;

	int p[100005];
	long long prefiksuk[100005];
	long long poz[100005];
	vector <long long> v;
	
int main (){
	
	int n,k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++){
		cin >> p[i];
	}
	
	prefiksuk[0] = p[0];
	if (n > 1){
		for (int i = 1; i < n; i++){
			prefiksuk[i] = prefiksuk[i - 1] + p[i]; 
		}
	}
	
	poz[0] = 0;
	if (p[0] > 0)poz[0] = p[0];
	
	if (n > 1){
		for (int i = 1; i < n; i++){
			if (p[i] > 0){
				poz[i] = poz[i - 1] + p[i]; 
			}else {
				poz[i] = poz[i - 1];
			}
		}
	}

	for (int br = 0; br < (n-k+1); br++){
		long long sol = 0;
		if (br == 0){
			if ((poz[n-1] - poz[k-1]) > 0){
				sol += (poz[n-1] - poz[k-1]);
			}
		}else if (br == (n-k)){
			if (poz[br-1] > 0){
				sol += poz[br-1];
			}
		}else {
			if (poz[br-1] > 0){
				sol += poz[br-1];
			}
			if ((poz[n-1] - poz[br+k-1]) > 0){
				sol += (poz[n-1] - poz[br+k-1]);
			}
		}
		
		
		if (br == 0){
			if (prefiksuk[k-1] > 0){
				sol += prefiksuk[k-1];
			}
		}else if (br == n-1){
			if ((prefiksuk[n-1]) - (prefiksuk[n-k-1]) > 0){
				sol += (prefiksuk[n-1]) - (prefiksuk[n-k-1]);
			}
		}else {
			if (((prefiksuk[br+k-1]) - (prefiksuk[br-1])) > 0){
				sol += ((prefiksuk[br+k-1]) - (prefiksuk[br-1]));
			}
		}
		
		v.push_back(sol);
	}
	
	sort (v.begin(), v.end());
	
	cout << v[v.size()-1];
	
	return 0;
}