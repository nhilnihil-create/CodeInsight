//赤(00) / 黄色(01) / 緑(10) / 青(11)と対応づける。
//□は| |と＝のandでできている。10は、1?と?0のandでできている. (?はそれぞれ任意のパターンにマッチする文字)
//「距離dのマス同士では、1ビット目が異なるようにしたい（2ビット目はどうでもよい)」だったら、|<-d->|ごとに0, 1, 0, 1…を割り振ればできる。
//2ビット目が～も同様。さて、この結果をa, bとおいたとき、2 * a + bの色で塗ったらどうなるでしょう。なんと、条件を満たせます。
//(c++ではa / b (a < 0, b > 0)の結果がfloor(a / b)と一致しないので面倒くさい)
#include <iostream>
#define rep(i, n) for (i = 0; i < n; i++)
using namespace std;

int h, w, d;
char *color = "RYGB";

int main() {
	int i, j;
	
	cin >> h >> w >> d;
	rep(i, h) {
		rep(j, w) {
			int a = ((i + j) / d) % 2;
			int b = ((i - j + w) / d) % 2;
			cout << color[2 * a + b];
		}
		cout << endl;
	}
	return 0;
}