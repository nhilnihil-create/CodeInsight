#include <bits/stdc++.h>

using namespace std;

int main() {
	string S,T; cin >> S >> T;
	vector<int> sm(S.size()+1),tm(T.size()+1);
	for(int i=0;i<S.size();++i) sm[i+1]=sm[i]+(S[i]=='A'?1:2);
	for(int i=0;i<T.size();++i) tm[i+1]=tm[i]+(T[i]=='A'?1:2);
	int q; cin >> q;
	while(q--) {
		int a,b,c,d; cin >> a >> b >> c >> d;
		--a, --c;
		bool f=(sm[b]-sm[a])%3==(tm[d]-tm[c])%3;
		cout << (f?"YES":"NO") << endl;
	}
	
	return 0;
}