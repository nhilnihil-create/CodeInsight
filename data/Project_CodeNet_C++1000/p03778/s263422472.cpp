#include <bits/stdc++.h>
using namespace std;

int main(){
	int w, a, b;
	cin >> w >> a >> b;
	int ans=0;
	if(b>a+w) ans=b-a-w;
	if(b+w<a) ans=a-b-w;
	cout << ans << endl;
}
