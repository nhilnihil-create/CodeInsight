#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int h, w;
	cin >> h >> w;
	int d;
	cin >> d;
	string f = "RYGB";
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(d % 2){
				int c = (i%2)*2+(j%2);
				cout << f[c];
				continue;
			}
			int x = i + j;
			int y = i - j;
			x %= 2*d;
			y %= 2*d;
			while(x < 0) x += 2*d;
			while(y < 0) y += 2*d;
			x /= (d);
			y /= (d);
			int c = 2*x+y;
			cout << f[c];
		}
		cout << endl;
	}
}
