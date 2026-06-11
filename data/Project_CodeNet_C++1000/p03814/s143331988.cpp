#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string s;
	cin >> s;
	int A, Z;
	rep(i, s.size()){
		if(s[i] == 'A') {
			A = i;
			break;
		}
	}
	for(int i = s.size()-1;i>=0;i--){
		if(s[i] == 'Z'){
			Z = i;
			break;
		}
	}
	cout << Z - A + 1 << endl;
}	











