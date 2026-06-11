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

int main(){
	deque < int > q; int N; cin >> N;
	for(int i = 1 ; i <= 3 * N ; ++i){int x; cin >> x; q.push_back(x);}
	sort(q.begin() , q.end()); long long sum = 0;
	for(int i = 1 ; i <= N ; ++i){q.pop_front(); q.pop_back(); sum += q.back(); q.pop_back();}
	cout << sum;
	return 0;
}
