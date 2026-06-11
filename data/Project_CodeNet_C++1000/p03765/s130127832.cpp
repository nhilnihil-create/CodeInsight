#include <bits/stdc++.h>
using namespace std;

int main(){
	string S,T;
	int q;
	cin >> S >> T >> q;
	vector<bool> ans(q);
	
	vector<int> ss;
	vector<int> tt;
	ss.push_back(0);
	tt.push_back(0);
	for(int i=0;i<S.size();i++){
		int add;
		if(S[i]=='A')add=1;
		else add=2;
		ss.push_back(ss[i]+add);
	}
	for(int i=0;i<T.size();i++){
		int add;
		if(T[i]=='A')add=1;
		else add=2;
		tt.push_back(tt[i]+add);
	}
	
	for(int i=0;i<q;i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(((ss[b]-ss[a-1])%3)==((tt[d]-tt[c-1])%3))ans[i]=true;
		else ans[i]=false;
	}
	for(int i=0;i<q;i++){
		if(ans[i])cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}