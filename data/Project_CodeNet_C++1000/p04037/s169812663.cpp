#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int a[maxn];
int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	int i = 0;
	while(i + 1 < n && a[i + 1] >= i + 2) i++;
	int l = 0, r = 0;
	for(int j = i + 1; j < n; j++) if(a[j] >= i + 1) r++;
	l = a[i] - i - 1;
	if((l % 2) != (r % 2)) cout << "First" << endl;
	else if(l % 2) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}
