#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int h,w,d,t1,t2;
int main(){
	cin>>h>>w>>d;
	for(int i=1;i<=h;++i,putchar(10))
		for(int j=1;j<=w;++j){
			t1=((i-j+w)/d)&1;
			t2=((i+j)/d)&1;
			putchar((t1<<1|t2)["RYGB"]);
		}
	return 0;
}