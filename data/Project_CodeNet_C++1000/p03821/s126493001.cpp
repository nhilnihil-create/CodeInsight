#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	cin >>n;
	vector<long long> a(n), b(n);

	for(int i = 0; i < n; ++i)
		cin >>a[i] >>b[i];
	
	long long sum = 0;
	for(int i = n - 1; i >= 0; --i){
		long long val = a[i] + sum;
		long long nxtmul = (val + b[i] - 1) / b[i] * b[i];
		sum += nxtmul - val;
	}
	cout <<sum <<'\n';
	return 0;
}
