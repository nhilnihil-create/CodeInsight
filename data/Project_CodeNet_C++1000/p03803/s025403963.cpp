#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	int A, B;
	cin >> A >> B;
	if(A==B) cout << "Draw" << endl;
	else if(A==1) cout << "Alice" << endl;
	else if(B==1) cout << "Bob" << endl;
	else if(A>B) cout << "Alice" << endl;
	else cout << "Bob" << endl;

	return 0;
}