#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;  
	int sum = 0, i = 1;
	set<int> s;
	while(sum < n) {
		sum += i;
		s.insert(i);
		i++;
	}
	s.erase(sum - n);
	for(auto j = s.begin(); j != s.end(); j++){
		cout << *j << endl;
	}
	return 0;	
}