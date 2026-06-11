#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	string S[3];
	rep(i,3) cin >> S[i];
	rep(i,3) reverse(S[i].begin(),S[i].end());
	char w;
	int t=0;
	while(1){
		if(S[t].empty()){
			w='A'+t;
			break;
		}
		char c=S[t].back();
		S[t].pop_back();
		t=c-'a';
	}
	cout << w << endl;

	return 0;
}