#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;
	int alp[26] = {0};
	rep(i,S.size()){
		int j = S[i] - 'a';
		alp[j] ++;
	}

	rep(i,26){
		if (alp[i] == 0) {
			printf("%c\n", 'a'+i);
			return 0;
		}
	}
	cout << "None" << endl;
	
	return 0;
}
