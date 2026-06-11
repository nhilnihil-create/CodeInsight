#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	int f = 0;
	while(n != 0){
		if(n%10 == 9) f = 1;
		n /= 10;
	}
	if(f == 1){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}