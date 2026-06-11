#include<bits/stdc++.h>
using namespace std;
int h,w,d;
const string color = "RBGY";
int main(){
	cin>>h>>w>>d;
	for( int i = 0; i < h; i++ ){
		for( int j = 0; j < w; j++ ){
			int a = i + j;
			int b = w + i - j;
			putchar(color[a/d%2+b/d%2*2]);
		} 
		puts("");
	}
	return 0;
}