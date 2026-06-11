#include<bits/stdc++.h>
const int MOD = 1e9+7;
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define ar array
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A,B;
	string op;
	cin >> A >> op >> B;

	if (op == "+") {
		cout << A+B << endl;
	} else if(op == "-") {
		cout << A-B << endl;
	} 
	return 0;
}
