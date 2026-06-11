// AtCoder Beginner Contest 047
// Problem A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	vector<int> v(0);
	cin >> a >> b >> c;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());
	if(v[0]+v[1] == v[2]){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}

	return 0;
}