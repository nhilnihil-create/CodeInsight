#include <iostream>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	string s[h][w];
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> s[i][j];
			if(s[i][j] == "snuke"){
				char k = 'A';
				k += j;
				cout << k << i + 1 << endl; 
			}
		}
	}
	return 0;
}