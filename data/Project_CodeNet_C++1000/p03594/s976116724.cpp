#include<bits/stdc++.h>

using namespace std;

int H , W , d;

char color[4] = { 'R', 'Y', 'G', 'B' };

inline int read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while((ch < '0') || (ch > '9')){
		if(ch == '-'){
			w = -1;
		}
		ch = getchar();
    }
   	while((ch >= '0') && (ch <= '9')){
   		s = s * 10 + ch - '0';
		ch = getchar();
	}
   	return s * w;
}

#pragma GCC optimize("inline,Ofast",3)
#pragma GCC optimize(2)
#pragma GCC optimize(3)

int main(){

	H = read();
	W = read();
	d = read();
	
	for(int i = 1 ; i <= H ; i++ ){
		for(int j = 1 ; j <= W ; j++ ){
			int x = i + j + W , y = i - j + W;
			cout << color[((x / d) & 1) * 2 + ((y / d) & 1)];
		}
		cout << endl;
	}

	return 0;
}