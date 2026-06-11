#include <iostream>
#include <string>

using namespace std;

int H, W;
string S;

int main(void)
{
	cin >> H >> W;
	for(int y = 1; y <= H; y++){
		for(int x = 0; x < W; x++){
			cin >> S;
			if(S == "snuke"){
				cout << (char)(x + 'A') << y << endl;
				return 0;
			}
		}
	}
}