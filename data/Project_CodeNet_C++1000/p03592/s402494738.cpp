#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, m, k;

int main(void){
	cin >> n >> m >> k;
	rep(i, n+1){
		rep(j, m+1){
			if(i*m + j*n - 2*i*j == k){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
