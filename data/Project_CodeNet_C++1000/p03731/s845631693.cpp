#include <iostream>
using namespace std;

int main() {
	int N,t;
	cin >> N >> t;
	long long arr[N];
	long long sum=0;
	for (int i=0; i<N; i++){
		cin>>arr[i];
	}
	for (int i=1; i<N; i++){
		int add = t<(arr[i]-arr[i-1]) ? t : (arr[i]-arr[i-1]);
		sum+=add;
	}
	sum += t;
	
	cout << sum << "\n";
}