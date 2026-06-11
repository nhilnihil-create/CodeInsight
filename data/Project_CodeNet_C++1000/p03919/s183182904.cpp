#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int h, w;
	string s[26][26];
	cin >> h >> w;
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			cin >> s[i][j];
		}
	}
	for(int i = 0;i < h;i++){
		char c = 'A';
		for(int j = 0;j < w;j++){
			if(s[i][j] == "snuke"){
				cout << c << i+1 << endl;
			}
			c++;
		}
	}
	return 0;
}