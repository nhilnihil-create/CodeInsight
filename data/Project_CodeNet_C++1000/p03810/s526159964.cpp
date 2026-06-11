#include <iostream>
using namespace std;

int gcd(int a,int b){
	if(a < b) swap(a,b);
	if(!b) return a;
	return gcd(b,a % b);
}

int main(){
	int n,a[100000];
	bool turn = true;
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	while(1){
		int gu = 0,one = 0;
		for(int i = 0;i < n;i++){
			if(a[i] % 2 == 0) gu++;
			if(a[i] == 1) one++;
		}
		if(gu % 2){
			if(turn) cout << "First" << endl;
			else cout << "Second" << endl;
			break;
		}else if(n - gu != 1 || (n - gu == 1 && one)){
			if(!turn) cout << "First" << endl;
			else cout << "Second" << endl;
			break;
		}
		if(a[0] % 2 == 1) a[0]--;
		int g = a[0];
		for(int i = 1;i < n;i++){
			if(a[i] % 2 == 1) a[i]--;
			g = gcd(g,a[i]);
		}
		for(int i = 0;i < n;i++) a[i] /= g;
		turn = !turn;
	}
	return 0;
}