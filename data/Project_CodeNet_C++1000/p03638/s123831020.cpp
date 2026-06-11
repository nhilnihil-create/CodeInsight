#include<bits/stdc++.h>
using namespace std;

int a[100005];
int rlt[105][105];
int main(){
	int h, w, n;
	cin >> h >> w >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	int cur = 0, cnt = 0;
	for(int i = 0; i < h; i ++){
		if(i % 2 == 0){
			for(int j = 0; j < w; j ++){
				rlt[i][j] = cur;
				a[cur] --;
				if(a[cur] == 0) cur ++; 
			}
		}
		else {
			for(int j = w - 1; j  >= 0; j --){
				rlt[i][j] = cur;
				a[cur] --;
				if(a[cur] == 0) cur ++; 
			}
		}
	}
	for(int i = 0; i < h; i ++){
		for(int j = 0; j < w; j ++){
			cout << rlt[i][j] + 1 << " \n"[j == w - 1];
		}
	}
}
