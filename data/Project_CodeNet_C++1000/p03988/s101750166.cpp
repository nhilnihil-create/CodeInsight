#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int bg = a.back();
	auto bad = [](){
		cout << "Impossible" << endl;
		exit(0);
	};
	if(count(a.begin(), a.end(), bg) < 2) bad();
	if(count(a.begin(), a.end(), a[0]) != 1 + (bg%2)) bad();
	int i = 0;
	for(int j = 0; j < n;){
		i = j;
		while(i < n && a[i] == a[j]) i++;
		if(j){
			if(a[j - 1] + 1 != a[j]) bad();
		}
		j = i;
	}
	cout << "Possible" << endl;
	return 0;
}

