#include <iostream>
using namespace std;
int main(){
	int M, N;
	cin>>M>>N;
	if (abs(M-N)>=2){
		cout << 0 << endl;
	}
	else if (M==N){
		long long s = 1;
		for (int i=1; i<=M; i++){
			s = s*i % 1000000007;
		}
		
		cout << s*s*2%1000000007;
	}
	else {
		long long s = 1;
		for (int i=1; i<=M; i++){
			s = s*i % 1000000007;
		}
		long long x = 1;
		for (int i=1; i<=N; i++){
			x = x*i % 1000000007;
		}
		cout << x*s %1000000007;
	}
}
