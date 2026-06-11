#include<bits/stdc++.h>
using namespace std;
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
int main(){
	int n;
	int a[100];
	vector<int> d(9);
	cin >> n;
	int c = 0;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		if (x < 400) {
			d[0] = 1;
		} else {
			if (x < 800) {
				d[1] = 1;
			} else {
				if (x < 1200) {
					d[2] = 1;
				} else {
					if (x < 1600) {
						d[3] = 1;
					} else {
						if (x < 2000) {
							d[4] = 1;
						} else {
							if (x < 2400) {
								d[5] = 1;
							} else {
								if (x < 2800) {
									d[6] = 1;
								} else {
									if ( x < 3200) {
										d[7] = 1;
									} else {
										c++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int ans = accumulate(d.begin(), d.end(), 0);
	if (ans == 0) {
		cout << 1 << " " << c;
	} else 
		cout << ans << " " << ans+c; 
	return 0;
}