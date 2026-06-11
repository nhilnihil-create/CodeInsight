#include <bits/stdc++.h>
using namespace std;
 
const double eps=1e-7;
int H,h,W,w;
inline int val(int i,int j,int a,int b) {return ((i%h)||(j%w)) ? a : b;}
int main() {
	cin>>H>>W>>h>>w;
	if((!(H%h)) && (!(W%w))) return puts("No"),0;
	int v=(1e9-1)/(h*w-1);
	if((long long)v*(H*W-(H/h)*h*(W/w)*w)<=((H/h)*(W/w))) return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=H;i++,cout<<'\n')
		for(int j=1;j<=W;cout<<val(i,j,v,-v*(h*w-1)-1)<<' ',j++);
}