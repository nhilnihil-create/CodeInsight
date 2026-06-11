#include<bits/stdc++.h>
using namespace std;

int main(){
	int N , arr[200003]; cin >> N;
	for(int i = 1 ; i <= 2 * N ; ++i) cin >> arr[i];
	sort(arr + 1 , arr + 2 * N + 1); long long sum = 0;
	for(int i = 1 ; i <= 2 * N ; i += 2) sum += arr[i];
	cout << sum; return 0;
}
