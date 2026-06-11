#include <bits/stdc++.h>
using namespace std;
int h,w,d;
char s[4]={'R','Y','G','B'};
int main(){
	cin>>h>>w>>d;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			int x=i+j+w;
			int y=i-j+w;
			putchar(s[((x / d) & 1) * 2 + ((y / d) & 1)]);
		}
		cout<<endl;
	}
}