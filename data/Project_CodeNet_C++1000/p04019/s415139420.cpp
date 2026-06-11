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
	string s; cin >> s;
	int cnt1 = (find(s.begin() , s.end() , 'N') != s.end()) + (find(s.begin() , s.end() , 'S') != s.end()) ,
		cnt2 = (find(s.begin() , s.end() , 'E') != s.end()) + (find(s.begin() , s.end() , 'W') != s.end());
	puts(cnt1 % 2 || cnt2 % 2 ? "No" : "Yes");
	return 0;
}
