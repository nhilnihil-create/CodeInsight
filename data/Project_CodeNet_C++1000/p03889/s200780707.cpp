#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[100007], b[100007];
int len;

bool judge() {
	for(int i = 0; i < len; i++)
		if(b[i] != a[len - 1 - i]) 
			return false;
	return true;
}
int main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin >> a;
	strcpy(b, a);
	len = strlen(a);
	for(int i = 0; i < len; i++)
		switch(b[i]) {
			case 'b': a[i] = 'd'; break;
			case 'd': a[i] = 'b'; break;
			case 'p': a[i] = 'q'; break;
			case 'q': a[i] = 'p'; break;
		}
	
	cout << (judge() ? "Yes\n" : "No\n");
	
	return 0;
}
