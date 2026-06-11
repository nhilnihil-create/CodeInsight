#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

int main(){
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n , m , k;
	cin >> n >> m >> k;

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i * (m - j) + j * (n - i) == k){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	
	cout << "No" << endl;
	return 0;
}
