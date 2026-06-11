#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	long long A,B,C,D;
	cin >> A >> B >> C >> D;
	
	long long diff_sum=B-A;
	
	for(int i=0;i<N;i++){
		long long diff_max=(N-1-i)*D-i*C;
		long long diff_min=(N-1-i)*C-i*D;
		if(diff_min<=diff_sum && diff_sum<=diff_max){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}