#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
	long long o = 0, p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0, ans = 1;
	string ss; cin >> ss;
	for (int hh = 0; hh < ss.size(); hh++) {
		if (ss[hh] == 'a') { a++; } if (ss[hh] == 'b') { b++; }
		if (ss[hh] == 'c') { c++; } if (ss[hh] == 'd') { d++; } if (ss[hh] == 'e') { e++; }
		if (ss[hh] == 'f') { f++; } if (ss[hh] == 'g') { g++; } if (ss[hh] == 'h') { h++; }
		if (ss[hh] == 'i') { i++; } if (ss[hh] == 'j') { j++; } if (ss[hh] == 'k') { k++; }
		if (ss[hh] == 'l') { l++; } if (ss[hh] == 'm') { m++; } if (ss[hh] == 'n') { n++; }
		if (ss[hh] == 'o') { o++; } if (ss[hh] == 'p') { p++; } if (ss[hh] == 'q') { q++; }
		if (ss[hh] == 'r') { r++; } if (ss[hh] == 's') { s++; } if (ss[hh] == 't') { t++; }
		if (ss[hh] == 'u') { u++; } if (ss[hh] == 'v') { v++; } if (ss[hh] == 'w') { w++; }
		if (ss[hh] == 'x') { x++; } if (ss[hh] == 'y') { y++; } if (ss[hh] == 'z') { z++; }
	}
	ans = ss.size() * (ss.size() - 1) / 2 + 1;
	ans -= a * (a - 1) / 2; ans -= b * (b - 1) / 2; ans -= c * (c - 1) / 2; ans -= d * (d - 1) / 2;
	ans -= e * (e - 1) / 2; ans -= f * (f - 1) / 2; ans -= g * (g - 1) / 2; ans -= h * (h - 1) / 2;
	ans -= i * (i - 1) / 2; ans -= j * (j - 1) / 2; ans -= k * (k - 1) / 2; ans -= l * (l - 1) / 2;
	ans -= m * (m - 1) / 2; ans -= n * (n - 1) / 2; ans -= o * (o - 1) / 2; ans -= p * (p - 1) / 2;
	ans -= q * (q - 1) / 2; ans -= r * (r - 1) / 2;
	ans -= s * (s - 1) / 2; ans -= t * (t - 1) / 2; ans -= u * (u - 1) / 2; ans -= v * (v - 1) / 2;
	ans -= w * (w - 1) / 2; ans -= x * (x - 1) / 2; ans -= y * (y - 1) / 2; ans -= z * (z - 1) / 2;
	cout << ans << endl;
	cin >> n;
}