#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	int freq[110000];
	for(int i = 0; i < 110000; i++) freq[i] = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		freq[a]++;
	}
	int s[m];
	int p[m];
	for(int i = 0; i < m; i++) s[i] = p[i] = 0;
	for(int i = 0; i < 110000; i++){
		p[i%m] += freq[i]/2;
		s[i%m] += freq[i]%2;
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		if((i+i) % m == 0){
			ans += (p[i]*2+s[i])/2;
			p[i] = 0;
			s[i] = 0;
		} else {
			//cout << s[i] << " " << s[m-i] << endl;
			while(1){
				if(s[i] > 0 && s[m-i] > 0){
					s[i]--;
					s[m-i]--;
					ans++;
					continue;
				}
				if(s[i] > 0 && p[m-i] > 0){
					s[i]--;
					p[m-i]--;
					s[m-i]++;
					ans++;
					continue;
				}
				if(s[m-i] > 0 && p[i] > 0){
					s[m-i]--;
					p[i]--;
					s[i]++;
					ans++;
					continue;
				}
				if(p[i] > 0){
					p[i]--;
					ans++;
					continue;
				}
				if(p[m-i] > 0){
					p[m-i]--;
					ans++;
					continue;
				}
				break;
			}
		}
	}
	cout << ans << endl;
}
