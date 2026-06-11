#include<iostream>
using namespace std; 
#define LL long long
LL A,B,C;
void getAns(){ 
	LL ta=A%2,tb=B%2,tc=C%2;
	if(ta==0 || tb==0 || tc==0) {
		cout<<"0"; return;
	}
	LL ans1= B*C*ta;
	LL ans2= A*C*tb;
	LL ans3= A*B*tc; 
	if(ans1>ans2) ans1=ans2;
	if(ans1>ans3) ans1=ans3;
	cout<<ans1;
} 
int main(){
	cin >> A >> B >> C;
	getAns();
	return 0;
} 