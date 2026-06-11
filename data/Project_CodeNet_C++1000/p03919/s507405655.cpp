#include<bits/stdc++.h>
using namespace std;
int main(){
	int H, W;
	string S;
	cin >> H >> W;
	char column;
	int row;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> S;
			if(S == "snuke"){
				column = 'A' + j;
				row = i + 1;
			}
		}
	}
	cout << column << row << endl;
	return 0;
}
