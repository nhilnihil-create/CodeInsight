#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
int main() {
	string S;
	cin>>S;
	rep(i,S.size()){
		if(i==4)cout<<' ';
		cout<<S[i];
	}
	cout<<endl;
}
