#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	int W,a,b; cin>>W>>a>>b;
	int ans=0;
	if(a<=b){
		ans = b - (a+W);
	}else{
		ans = a - (b+W);
	}

	if(ans<0){
		cout << 0 << endl;
	}else{
		cout << ans << endl;
	}
}
