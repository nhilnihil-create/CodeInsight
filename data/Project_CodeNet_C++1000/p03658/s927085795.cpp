#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, count;
	cin>>N>>count;
	int arr[N];
	for (int i=0; i<N; i++){
		cin >> arr[i];
	}
	sort (arr, arr+N);
	//string a = "abc";
	//reverse(a.begin(), a.end());
	//cout << a << endl;
	//for (int i=0; i<N; i++){
	//	cout << arr[i];
	//}cout << endl;
	int sum=0;
	for (int i=N-1; i>=N-count; i--){
		sum+=arr[i];
	}
	cout << sum << endl;
}