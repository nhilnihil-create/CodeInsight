#include<iostream>
#include<algorithm>
using namespace std;

int num[101];//各a_iの個数をカウントする
int main() {
	int N;
	cin >> N;
	int mx = 0, mn = 1000;//a_iの最大値と最小値
	for(int i=0; i<N; i++){
		int a; cin >> a;
		mx = max(mx, a);
		mn = min(mn, a);
		num[a]++;
	}
	bool ok = true;
	//maxが偶数の時
	if (mx % 2 == 0) {
		//minはmaxの半分でなければダメ
		if (mn != mx / 2)ok = false;

		//a_iがminとなるiは1つだけで、それ以上増やせない
		if (num[mn] != 1)ok = false;

		//a_iがmn+1~mxとなるiは少なくとも2つなのでそれを下回っていればImpossible
		for (int i = mn+1; i <= mx; i++){
			if (num[i] < 2) {
				ok = false;
			}
		}
	}
	//maxが奇数の時
	else {
		//minは(max+1)の半分でなければダメ
		if (mn != (mx + 1) / 2)ok = false;

		//a_iがmaxとなるiは2つだけで、それ以上増やせない
		if (num[mn] != 2)ok = false;

		//a_iがmn+1~mxとなるiは少なくとも2つなのでそれを下回っていればImpossible
		for (int i = mn + 1; i <= mx; i++) {
			if (num[i] < 2) {
				ok = false;
				if (ok)cout << "ok" << endl;
			}
		}
	}
	if (ok) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
}