#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a;
	cin >> n;
	set<int> s;
	while(n--){
		cin >> a;
		if (s.count(a)) s.erase(a);
		else s.insert(a);
	}
	cout << s.size();
	
}
