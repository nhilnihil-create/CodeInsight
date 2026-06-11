#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(auto &i:A)cin >> i;
	
	long long ans=A[0]-1;
	A[0]=1;
	int c=1;
	for(int i=0;i<N;i++){
		if(A[i]==c)c++;
		else ans+=(A[i]+c-1)/c-1;
	}
	cout << ans << endl;
	return 0;
}