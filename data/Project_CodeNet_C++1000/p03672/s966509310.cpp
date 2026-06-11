#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	int length = (int)s.size();
	for(int i = length -2; i >0; i -= 2){
		if(s.substr(0,i/2) == s.substr(i/2,i/2)){
			cout << i << endl;
			return 0;
		}
	}
}

// cout << fixed << setprecision(15) <<  << endl;