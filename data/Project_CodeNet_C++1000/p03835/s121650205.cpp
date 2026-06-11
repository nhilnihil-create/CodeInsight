#include <bits/stdc++.h>
using namespace std;

int main(){
	int k, s;
	int num=0;
	cin >> k >> s;
	for(int i=0; i<=k; i++){
		for(int j=0; j<=k; j++){
			int m=s-i-j;
			if(0<=m && m<=k) num++;
		}
	}
	cout << num << endl;
}
