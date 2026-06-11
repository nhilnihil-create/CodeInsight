#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<int(n); i++)
using namespace std;
int main(){
	int H, W, d; cin >> H >> W >> d;
	string c = "RYGB";
	if(d%2==0){
		rep(i, H){
			rep(j, W) cout << c[2*(((i+j)/d)%2) + ((i-j+2000*d)/d)%2];
			cout << "\n";
		}
	}else{
		rep(i, H){
			rep(j, W) cout << c[(i+j)%2];
			cout << "\n";
		}
	}
	return 0;
}
