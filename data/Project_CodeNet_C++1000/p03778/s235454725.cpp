#include<iostream>
#include<cmath>
using namespace std;
int main(void){
	int w,a,b;
	cin>>w>>a>>b;
	int smaller = min(a,b);
	int larger = max(a,b);
	if(smaller + w >= larger)cout<<0<<endl;
	else cout<<(larger - smaller -w)<<endl;
	return 0;
}