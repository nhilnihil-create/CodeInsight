#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int f = 0;
	if(a+b == c) f = 1;
	if(b+c == a) f = 1;
	if(c+a == b) f = 1;
	if(f == 1){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}