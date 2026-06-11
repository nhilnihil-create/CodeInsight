#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin>>N;
	int arr[N];
	for (int i=0; i<N; i++){
		cin>>arr[i];//{02244}{11335577}
	}
	sort(arr, arr+N);
	bool mis=0;
	if (N%2==0){;
		for (int i=0; i<N-1; i+=2){
			if (arr[i]!=arr[i+1]){
				mis=1;
			}	
		}
		if (mis==0){
			long long n=1;
			for (int i=0; i<N/2; i++){
				n=(n*2);
				n=n%1000000007;
			}
			cout << n << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	else{
		for (int i=1; i<N-2; i+=2){
			if (arr[i]!=arr[i+1]){
				mis=1;
			}	
		}
		if (mis==0){
			long long n=1;
			for (int i=0; i<N/2; i++){
				n=(n*2);
				n=n%1000000007;
			}
			cout << n << endl;
		}
		else{
			cout << 0 << endl;
		}
		
	}
}