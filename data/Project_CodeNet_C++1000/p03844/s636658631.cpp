#include<bits/stdc++.h>
using namespace std;

int x,y,z;
char c;

int main() {
	cin >> x >> c >> y;
	if (c == '-') cout << x-y; else cout << x + y;
}