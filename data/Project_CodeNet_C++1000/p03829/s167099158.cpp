#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	long long A,B,ans=0;
	cin >> N >> A >> B;
	vector<long long> X(N);
	for(auto &i:X)cin >> i;
	
	for(int i=0;i<N-1;i++){
		ans+=min(A*(X[i+1]-X[i]),B);
	}
	cout << ans << endl;
	return 0;
}