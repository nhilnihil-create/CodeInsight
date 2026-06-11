#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string S;
	cin >> S;
	vector<int> alphabet(26);
	int N = S.size();
	rep(i,N){
		alphabet[S[i] - 'a']++;
	}
	rep(i,26){
		if(alphabet[i] >= 2){
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;
	return 0;
			

}










