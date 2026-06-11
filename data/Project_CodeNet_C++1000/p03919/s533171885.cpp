#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
int main() {
	int H,W;
	cin>>H>>W;
	string S[H][W];
	rep(i,H)rep(j,W)
	cin>>S[i][j];
	rep(i,H)rep(j,W){
		if(S[i][j]=="snuke"){
			cout<<char(j+'A')<<i+1<<endl;
			return 0;
		}
	}
}