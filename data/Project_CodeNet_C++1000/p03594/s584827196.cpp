#include <iostream>
using namespace std;

int H,W,D;
char A[2000][2000];
int main(){
	cin >> H >> W >> D;
	for(int i=0;i<2000;i++){
		for(int j=0;j<2000;j++){
			if((i/D)%2==0 && (j/D)%2==0) A[i][j] = 'R';
			if((i/D)%2==0 && (j/D)%2==1) A[i][j] = 'Y';
			if((i/D)%2==1 && (j/D)%2==0) A[i][j] = 'G';
			if((i/D)%2==1 && (j/D)%2==1) A[i][j] = 'B';
		}
	}
	int count = 0;
	while(count<H){
		int i = 510-count,j = count,c = 0;
		while(c<W){
			cout << A[i][j] << (c!=W-1? "":"\n");
			i++;j++;
			c++;
		}
		count++;
	}
}