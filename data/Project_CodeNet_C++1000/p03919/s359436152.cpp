#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
char az(int n){
	if (n == 0)return 'A';
	if (n == 1)return 'B';
	if (n == 2)return 'C';
	if (n == 3)return 'D';
	if (n == 4)return 'E';
	if (n == 5)return 'F';
	if (n == 6)return 'G';
	if (n == 7)return 'H';
	if (n == 8)return 'I';
	if (n == 9)return 'J';
	if (n == 10)return 'K';
	if (n == 11)return 'L';
	if (n == 12)return 'M';
	if (n == 13)return 'N'; 
	if (n == 14)return 'O';
	if (n == 15)return 'P';
	if (n == 16)return 'Q';
	if (n == 17)return 'R';
	if (n == 18)return 'S';
	if (n == 19)return 'T';
	if (n == 20)return 'U';
	if (n == 21)return 'V';
	if (n == 22)return 'W';
	if (n == 23)return 'X';
	if (n == 24)return 'Y';
	if (n == 25)return 'Z';

}

int W, H;
char s;
int ans;
int main(){
	scanf("%d %d", &W, &H);
	for (int x = 0; x < W; x++){
		for (int y = 0; y < H; y++){
			string c;
			cin >> c;
			if (c == "snuke"){
				s = az(y);
				ans = x + 1;
				
			}
			
		}
	}
	printf("%c%d\n", s, ans);
	return 0;
}