#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	string o, e;
	cin >> o >> e;
	e += "\n";
	rep(i, o.size()){
		cout << o[i] << e[i];;
	}
	return 0;
}