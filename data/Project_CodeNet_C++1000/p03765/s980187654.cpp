#include <bits/stdc++.h>

using namespace std;

string S, T;
int q;
int s[100050], t[100050];
int main(){
	cin >> S >> T;
	for(int i=0; i<S.length(); ++i){
		if(S[i] == 'A') s[i+1] = 1;
		else s[i+1] = 2;
		s[i+1] += s[i];
	}
	for(int i=0; i<T.length(); ++i){
		if(T[i] == 'A') t[i+1] = 1;
		else t[i+1] = 2;
		t[i+1] += t[i];
	}
	cin >> q;
	while(q--){
		int a,b,c,d; cin >> a >> b >> c >> d;
		if((s[b]-s[a-1])%3 == (t[d]-t[c-1])%3) cout << "YES\n";
		else cout << "NO\n";
	}
}
