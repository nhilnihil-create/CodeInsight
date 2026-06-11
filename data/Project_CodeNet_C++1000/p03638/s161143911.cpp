#include <bits/stdc++.h>
using namespace std;
const int N = 111;
int ans[N][N];
int h, w;
int n;
int a[N * N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> h >> w;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int i = 0, j = 0;
	for(int c = 1; c <= n; c++){
		while(a[c]--){
			ans[i][j] = c;
			if(i & 1){
				j--;
				if(j == -1){
					j = 0;
					i++;
				}
			}
			else{
				j++;
				if(j == w){
					j = w - 1;
					i++;
				}
			}
		}
	}
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			cout << ans[i][j] << " \n"[j == w - 1];
	return 0;
}
