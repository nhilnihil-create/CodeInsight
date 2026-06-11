#include<bits/stdc++.h>
using namespace std;

int table[1010][1010];
int table2[1010][1010];
typedef long long LL;
int main() {
	int N = 1010;
	int H,W,D;
	cin >> H >> W >> D;
	char c[4] = {'R', 'G', 'B', 'Y'};
	/*
	for(int i=0; i<10; i++, cout << endl)
		for(int j=0; j<10; j++)
			cout << table[i][j] << " ";
	*/
	if(D%2 == 1)  {
		for(int i=0 ;i<H; i++, cout << endl)
			for(int j=0; j<W; j++)
				cout << c[(i+j)%2];
		
	}

	else {
		
	for(int i=0; i<1010; i++) {
		for(int j=0; j<1010; j++) {
			table[i][j] = (2*(i/D)+j/D) % 4 ;
		}
		
	}
		/*
		for(int i=0; i<10; i++, cout << endl)
		for(int j=0; j<10; j++)
			cout << table[i][j] << " ";
		*/
		
		for(int i=0; i<H; i++, cout << endl) 
			for(int j=0; j<W; j++)
				cout << c[table[500 + i - j][0 + i + j]];
		
	}
	
	
	return 0;
}