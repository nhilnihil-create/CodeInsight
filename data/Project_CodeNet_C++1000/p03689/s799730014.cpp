#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int H, W, h, w;
	cin >> H >> W >> h >> w;

	if(H%h==0 && W%w==0){
		cout << "No" << endl;
		return 0;
	}else if(W%w!=0){
		int s[W+1];
		int p=W/w, q=W%w;
		for(int i=0; i<=W; i++){
			s[i]=-(i/w);
			if(i%w==q) s[i]+=p+1;
		}

		cout << "Yes" << endl;
		for(int i=1; i<=H; i++){
			for(int j=1; j<=W; j++){
				cout << s[j]-s[j-1] << " ";
			}
			cout << endl;
		}
	}else{
		int s[H+1];
		int p=H/h, q=H%h;
		for(int i=0; i<=H; i++){
			s[i]=-(i/h);
			if(i%h==q) s[i]+=p+1;
		}

		cout << "Yes" << endl;
		for(int i=1; i<=H; i++){
			for(int j=1; j<=W; j++){
				cout << s[i]-s[i-1] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}