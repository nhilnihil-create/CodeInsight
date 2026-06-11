#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W = 0;
	cin >> H >> W;
	int i;
	for(i = 0;true;i++){
		string s;
		cin >> s;
		if(s == "snuke"){
			break;
		}
	}
	int a;
	a = i / W + 1;
	char b;
	if(i % W == 0){
		b = 'A';
	}
	if(i % W == 1){
		b = 'B';
	}
	if(i % W == 2){
		b = 'C';
	}
	if(i % W == 3){
		b = 'D';
	}
	if(i % W == 4){
		b = 'E';
	}
	if(i % W == 5){
		b = 'F';
	}
	if(i % W == 6){
		b = 'G';
	}
	if(i % W == 7){
		b = 'H';
	}
	if(i % W == 8){
		b = 'I';
	}
	if(i % W == 9){
		b = 'J';
	}
	if(i % W == 10){
		b = 'K';
	}
	if(i % W == 11){
		b = 'L';
	}
	if(i % W == 12){
		b = 'M';
	}
	if(i % W == 13){
		b = 'N';
	}
	if(i % W == 14){
		b = 'O';
	}
	if(i % W == 15){
		b = 'P';
	}
	if(i % W == 16){
		b = 'Q';
	}
	if(i % W == 17){
		b = 'R';
	}
	if(i % W == 18){
		b = 'S';
	}
	if(i % W == 19){
		b = 'T';
	}
	if(i % W == 20){
		b = 'U';
	}
	if(i % W == 21){
		b = 'V';
	}
	if(i % W == 22){
		b = 'W';
	}
	if(i % W == 23){
		b = 'X';
	}
	if(i % W == 24){
		b = 'Y';
	}
	if(i % W == 25){
		b = 'Z';
	}
	cout << b << a << endl;
}