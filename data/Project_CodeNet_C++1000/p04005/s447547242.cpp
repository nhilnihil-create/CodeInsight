#include<iostream>
using namespace std;

long long A,B,C;
long long AB,BC,AC;
long long red,blue;
long long temp1,temp2,temp3,ans;


int main(){
	cin>>A>>B>>C;
	AB=A*B;
	BC=B*C;
	AC=A*C;
	
	if(C%2==0)temp1=0;
	else temp1=AB;
	if(A%2==0)temp2=0;
	else temp2=BC;
	if(B%2==0)temp3=0;
	else temp3=AC;
	
	ans=temp1<temp2?temp1:temp2;
	ans=ans<temp3?ans:temp3;
	cout<<ans<<endl;
} 