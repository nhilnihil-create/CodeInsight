#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int A, B, C;
	cin >> A >> B >> C;
	for(int i = 0; i < B; ++i){
		if((A*i)%B==C) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}










