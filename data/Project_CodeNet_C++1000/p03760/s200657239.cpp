#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string o,e;
	cin >> o >> e;
	int size = max((int)o.size(), (int)e.size());
	if((int)e.size() != (int)o.size()){
		size--;
		rep(i,size) cout << o[i] << e[i];
		cout << o[o.size()-1] << endl;
	}
	else{
		rep(i,size) cout << o[i] << e[i];
		cout << endl;
	}
}