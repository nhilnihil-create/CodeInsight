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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/* 大文字を小文字に変換 tolower*/
/* 小文字を大文字に変換 toupper*/
 
int main () {
	int a,b;
	cin >> a >>b;
	if (a ==1) {
		if (a == b) cout << "Draw" << endl;
		else cout << "Alice" << endl;
	return 0;
	}
	if (b ==1) {
		cout << "Bob" << endl;
	return 0;
	}
	if (a == b) cout << "Draw" << endl;
	else if (a > b) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}
