#include <bits/stdc++.h>
#define Y "Yes"
#define N "No"
using namespace std;

int a, b, c;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c;
	if (c >= a && c <= b) cout << Y;
	else cout << N;
}