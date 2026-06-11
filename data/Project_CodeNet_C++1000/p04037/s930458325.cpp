#include <bits/stdc++.h>
using namespace std;
int g[100005];
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> g[i];
	sort(g+1 , g+n+1 , greater<int>());//g[n+1] = 0
	
	int ans = -1;
	for(int i=1;i<=n && ans == -1;i++) {
		if(g[i+1] == i) {
			int pos = i+1;
			while(pos < n && g[pos+1] == i)
				pos++;
			if(g[i] == i) {
				if((pos-i) % 2 == 0)
					ans = 1;
				else 
					ans = 0;
			} else {
				if((pos-i) % 2 == 0 && (g[i]-i) % 2 == 0)
					ans = 1;
				else 
					ans = 0;
			}
		} else if(g[i+1] < i) {
			if((g[i]-i) % 2 == 0)
				ans = 1;
			else 
				ans = 0;
		}
	}
	if(ans == 0)
		cout << "First" << endl;
	else 
		cout << "Second" << endl;
	return 0;
}
