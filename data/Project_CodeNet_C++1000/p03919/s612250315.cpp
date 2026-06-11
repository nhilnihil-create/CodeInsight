#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int H,W;
	cin>>H>>W;
	string s[H][W];
	for(int h=0; h<H; h++){
		for(int w=0; w<W; w++){
			cin >> s[h][w];
			if(s[h][w]=="snuke"){
				cout<<
				(char)('A'+w)<<h+1<<endl;
			}
		}
	}
	return 0;
}