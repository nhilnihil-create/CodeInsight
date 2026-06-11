#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int main(){
	int H, W, h, w; cin >> H >> W >> h >> w;
	if(H % h + W % w == 0) cout << "No" << "\n";
	else{
		cout << "Yes" << "\n";
		int ans[H][W];
		if(H % h != 0){
			int a = H / h + 1;
			int b = -a * (h - 1) - 1;
			for(int i=0; i<H; i++){
				for(int j=0; j<W; j++){
					if(i % h == h - 1) cout << b << " ";
					else cout << a << " ";
				}
				cout << "\n";
			}
		}else{
			int a = W / w + 1;
			int b = -a * (w - 1) - 1;
			for(int i=0; i<H; i++){
				for(int j=0; j<W; j++){
					if(j % w == w - 1) cout << b << " ";
					else cout << a << " ";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}