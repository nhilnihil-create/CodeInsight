#include<bits/stdc++.h>
using namespace std;
int main () {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int sx=x1,sy=y1,tx=x2,ty=y2;
	while (y1 != ty) {
		if (y1 > ty) {
			cout <<"D";y1--;
		}
		if (y1 < ty) {
			cout <<"U";y1++;
		}
	}
	while (x1 != tx) {
		if (x1 > tx) {
			cout <<"L";x1--;
		}
		if (x1 < tx) {
			cout <<"R";x1++;
		}
	}
	while (y2 != sy) {
		if (y2 > sy) {
			cout <<"D";y2--;
		}
		if (y2 < sy) {
			cout <<"U";y2++;
		}
	}
	while (x2 != sx) {
		if (x2 > sx) {
			cout <<"L";x2--;
		}
		if (x2 < sx) {
			cout <<"R";x2++;
		}
	}
	cout <<"L";
	x1=sx-1,y1=sy,x2=tx,y2=ty+1;
	while (y1 != y2) {
		if (y1 > y2) {
			cout <<"D";y1--;
		}
		if (y1 < y2) {
			cout <<"U";y1++;
		}
	}
	while (x1 != x2) {
		if (x1 > x2) {
			cout <<"L";x1--;
		}
		if (x1 < x2) {
			cout <<"R";x1++;
		}
	}
	cout << "D";
	cout << "R";
	x1=sx,y1=sy-1,x2=tx+1,y2=ty;
	while (y2 != y1) {
		if (y2 > y1) {
			cout <<"D";y2--;
		}
		if (y2 < y1) {
			cout <<"U";y2++;
		}
	}
	while (x2 != x1) {
		if (x2 > x1) {
			cout <<"L";x2--;
		}
		if (x2 < x1) {
			cout <<"R";x2++;
		}
	}
	cout << "U";
	return 0;
}