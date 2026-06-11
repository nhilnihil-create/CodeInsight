#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000000 + 10;

char a[MAXN],c[MAXN];
int b,sum,l;
int main() {
	cin>>a;
	b = strlen(a);
	for(int i = b - 1; i >= 0; i--) {
		c[sum] = a[i];
		if(c[sum] == 'b') c[sum] = 'd';
		else if(c[sum] == 'd') c[sum] = 'b';
		else if(c[sum] == 'p') c[sum]='q';
		else if(c[sum] == 'q') c[sum]='p';
		sum++;
	}
	for(int i = 0; i <= b - 1; i++) {
		if(a[i] != c[i]) {
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}