#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	LL N, A, B;
	cin >> N >> A >> B;
	LL m=B+A*(N-1), M=A+B*(N-1);
	cout << max(0LL,M-m+1) << endl;

	return 0;
}