#include<bits/stdc++.h>
using namespace std;

/*
  REMEMBER:
  1.Think TWICE, code ONCE!
  Are there any counterexamples to your algo?
	
  2.Be careful about the BOUNDARIES in your algo!
  N=1? P=1? Is P a prime? Something about 0?
	
  3.Never make STUPID MISTAKES!
  Integer overflow? Array size? Time complexity? Memory usage? Precition error?
*/

long long sum; int arr[100003] , N;

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
	for(int i = 1 ; i <= N ; ++i){
		sum += arr[i] / 2; arr[i] %= 2;
		if(arr[i] && arr[i + 1]){--arr[i + 1]; --arr[i]; ++sum;}
	}
	cout << sum;
	return 0;
}
