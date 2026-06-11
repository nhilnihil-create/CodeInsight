#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string w;
	cin >> w;
	int N = w.size();
	vector<int> alphabet(26);
	rep(i,N){
		++alphabet[w[i] - 'a'];
	}
	rep(i,26){
		if(alphabet[i]%2!=0){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}










