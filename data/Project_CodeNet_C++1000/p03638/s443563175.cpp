#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1204;
int h,w,n;
int ma[MAXN][MAXN],a[20001];
void solve(){
	cin >> h >> w >> n;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	int tot = n;
	for(int i = 1;i <= h;i ++){
		if(i % 2){
			for(int j = 1;j <= w;j ++){
				ma[i][j] = tot,a[tot] --;
				if(a[tot] == 0) tot --;
			}
		}
		else{
			for(int j = w;j >= 1;j --){
				ma[i][j] = tot,a[tot] --;
				if(a[tot] == 0) tot --;
			}
		} 
	}
	for(int i = 1;i <= h;i ++){
		for(int j = 1;j <= w;j ++){
			cout << ma[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

int main(){
	solve();
	return 0;
} 