#include<bits/stdc++.h>
using namespace std;
char mp[23][23];
int cnt[29];
int main()
{
	int Q,n,m; 
		scanf("%d%d",&n,&m);
		bool fail = 0;
		memset(cnt,0,sizeof(cnt));
		for(register int i=1;i<=n;++i) {
			scanf("%s",mp[i]);
			for(register int j=0;j<m;++j)
			cnt[mp[i][j] - 'a'] ++;
		}
		if ((m&1) && (n&1)) {
			int l1 = (n + 1)/2 - 1, l2 = (m + 1)/2 - 1;
			int c1 = l1 + l2,lim = l1 * l2; bool fl = 0;
			for(register int i=0;i<26;++i) {
				if (!cnt[i]) continue;
				int h  = cnt[i] / 4;
				int Y = cnt[i] % 4;
				if (h > lim) {
					h -= lim;
					lim = 0;
					Y += h * 4;
				} else lim -= h;
				if (Y & 1) {
					if (fl) {
						fail = 1;
						break;
					}
					Y --; fl = 1;
				}
				Y /= 2;
				if (c1 >= Y) c1 -= Y;
				else {
					fail = 1;
					break;
				}
			}
		}
		else if ((m&1)||(n&1)) {
			int lim,c = (m&1) ? n : m;
			lim = (n * m - c)/4; c /= 2;
			for(register int i=0;i<26;++i) {
				if (!cnt[i]) continue;
				if (cnt[i]&1) {
					fail = 1;
					break;
				}
				int Y = cnt[i]%4,h = cnt[i]/4;
				if (h > lim) {
					h -= lim;
					lim = 0;
					Y += h * 4;
				} else lim -= h;
				Y /= 2;
				if (c >= Y) c -= Y;
				else {
					fail = 1;
					break;
				}
			}
		}
		else {
			for(register int i=0;i<26;++i) 
			if (cnt[i] % 4 != 0) {
				fail = 1;
				break;
			}
		}
		if (fail) puts("No");
		else puts("Yes");
}