#include <bits/stdc++.h>
using namespace std;

int main(){
	string a, b, c;
	cin >> a >> b >> c;
	if(*(a.end()-1) == *(b.begin()) && *(b.end()-1) == *(c.begin()))
		printf("YES\n");
	else printf("NO\n");
}
