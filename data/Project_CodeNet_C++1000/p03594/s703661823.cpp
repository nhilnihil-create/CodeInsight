#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	int H, W, d;
	while(cin >> H >> W >> d){
		for(int i=0;i<H;i++){
			string res(W, '.');
			for(int j=0;j<W;j++){
				if(d % 2){
					res[j] = "RG"[(i+j)%2];
				} else {
					int a = (i+j)/2/(d/2)%2;
					int b = (i-j+W)/2/(d/2)%2;
					res[j] = "RGBY"[2*a+b];
				}
			}
			cout << res << endl;
		}
	}
}