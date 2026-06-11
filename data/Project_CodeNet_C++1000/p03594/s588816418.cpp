#include <iostream>
using namespace std;

int ans[510][510];
char p[4]={'R', 'Y', 'G', 'B'};

int main() {
	int H, W, d;
	cin >> H >> W >> d;
	if(d%2){
	    for(int i=0; i<H; ++i){
	        for(int j=0; j<W; ++j){
	            ans[i][j]=(i+j)%2;
	        }
	    }
	}else{
	    for(int i=1-H; i<W; ++i){
	        for(int j=max(-i, 0); j<H && i+j<W; ++j){
	            ans[j][i+j] = ((i+1000)/d)%2 + (((i+2*j)/d)%2)*2;
	        }
	    }
	}
	for(int i=0; i<H; ++i){
	    for(int j=0; j<W; ++j){
	        cout << p[ans[i][j]];
	    }
	    cout << endl;
	}
	return 0;
}
