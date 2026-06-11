#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	bool ok = false;		
	vector<LL>A(3);
	rep(i,3) {
		cin >> A[i];
		if(A[i]%2==0) ok = true;
	}
	sort(A.begin(),A.end());
	if(ok) cout << 0 << endl;
	else cout << A[0]*A[1] << endl;

}












