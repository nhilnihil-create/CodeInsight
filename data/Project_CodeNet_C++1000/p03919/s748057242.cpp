#include <iostream> 
using namespace std;
 
int main(){
	int H, W;
	cin >> H >> W;
	char alphabets[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			string input;
			cin >> input;
			if(input == "snuke"){
				cout << alphabets[j] << i + 1 << endl;
				return 0;
			}
		}
	}
}