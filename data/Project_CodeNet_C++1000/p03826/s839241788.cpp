#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int areaa=a*b;
	int areab=c*d;
	int ans=max(areaa, areab);
	cout << ans << endl;
}
