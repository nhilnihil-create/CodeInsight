#include <iostream>
#define N 200005
using namespace std;
int n, mn, mj, d[N], e[N], c[N], x[30];
string a, s;
int main() {
	int i, j;
	cin>>a;
	n = a.size();
	a = '.' + a;
	for(i=0; i<26; i++) x[i] = n+1;
	for(i=n; i>=0; i--) {
		mn = N;
		for(j=0; j<26; j++)
			if(d[x[j]] < mn) mn = d[x[j]], mj = j;
		d[i] = mn + 1;
		e[i] = x[mj];
		c[i] = mj;
		x[a[i]-'a'] = i;
	}
	for(i=0; i<=n; i=e[i]) s += c[i]+'a';
	cout<<s;
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////