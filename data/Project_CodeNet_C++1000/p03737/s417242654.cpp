#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
/* 大文字を小文字に変換 */
char toupr(char c);
/* 小文字を大文字に変換 */
char tolower(char c);
 
int main() {
	string a,b,c;
	cin >> a >> b >>c;
	cout << toupr(a[0])   << toupr(b[0]) << toupr(c[0]) << endl;
}
char tolower(char c) {return (c + 0x20);}
char toupr(char c) {return (c - 0x20);}

