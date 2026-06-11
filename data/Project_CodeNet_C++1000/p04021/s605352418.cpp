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

int arr[100003] , N , lsh[100003];

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i){cin >> arr[i]; lsh[i] = arr[i];}
	sort(lsh + 1 , lsh + N + 1); for(int i = 1 ; i <= N ; ++i) arr[i] = lower_bound(lsh + 1 , lsh + N + 1 , arr[i]) - lsh;
	int cnt = 0; for(int i = 1 ; i <= N ; ++i) cnt += (arr[i] ^ i) & 1;
	cout << cnt / 2; return 0;
}
