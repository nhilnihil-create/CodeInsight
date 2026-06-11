#include <iostream>
using namespace std;
int main(){
	int a,s,g;
	cin>>a;
	s=a/10;
	g=a%10;
	if(s==9||g==9) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}