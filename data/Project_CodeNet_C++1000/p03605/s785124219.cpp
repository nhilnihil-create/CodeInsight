#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define int long long

signed main(){
	int N; cin >> N;
	bool ok = false;
	if(N%10 == 9) ok = true;
	if(N >= 90) ok = true;
	if(ok) cout <<  "Yes" << endl;
	else cout << "No" << endl;
}