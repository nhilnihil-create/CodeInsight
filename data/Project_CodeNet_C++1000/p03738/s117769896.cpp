#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string a, b;

int main(void){
	cin >> a >> b;
	int n, m;
	n = a.size();
	m = b.size();
	if(n > m) cout << "GREATER" << endl;
	else if(n < m) cout << "LESS" << endl;
	else{
		if(a > b) cout << "GREATER" << endl;
		else if(a < b) cout << "LESS" << endl;
		else cout << "EQUAL" << endl;
	}
	return 0;
}
