#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int N,A,B,c1=0,c2=0;
	string S;
	cin >> N >> A >> B >> S;

	rep(i,N) {
		bool ok=0;
		if(S.at(i) == 'a') {
			if(c1 < A+B)
				++c1, ok=1;
		} else if(S.at(i) == 'b') {
			if(c1<A+B && c2<B)
				++c1, ++c2, ok=1;
		}
		
		cout << ((ok) ? "Yes" : "No") << endl;
	}
}