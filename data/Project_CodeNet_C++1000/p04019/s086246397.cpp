#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string S;
	cin >> S;
	vector<bool> news(4, false);
	rep(i,S.size()){
		if(S[i] == 'N') news[0] = true;
		if(S[i] == 'W') news[1] = true;
		if(S[i] == 'S') news[2] = true;
		if(S[i] == 'E') news[3] = true;
	}
	if(news[0] == news[2]&&news[1] == news[3]) cout << "Yes" << endl;
	else cout << "No" << endl;

			
}












