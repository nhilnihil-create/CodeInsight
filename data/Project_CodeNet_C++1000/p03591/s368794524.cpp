#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
	string s;
	cin >> s;
	bool f = true;
	if(s.size() >= 4){
		if(s.at(0) != 'Y') f = false;
		if(s.at(1) != 'A') f = false;
		if(s.at(2) != 'K') f = false;
		if(s.at(3) != 'I') f = false;
	}else{
		f = false;
	}
	if(f == true){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}