#include<iostream>
using namespace std;
#include<cmath>
long long A,B,C;
long long mm;
long long box1,box2,ans;
int main()
{
	cin>>A>>B>>C;
	mm=A>>1;
	box1=mm*B*C;
	box2=(A-mm)*B*C;
	ans=abs(box1-box2);
	
	mm=B>>1;
	box1=mm*A*C;
	box2=(B-mm)*A*C;
	if(abs(box1-box2)<ans)
	ans=abs(box1-box2);
	
	
	mm=C>>1;
	box1=mm*B*A;
	box2=(C-mm)*B*A;
		if(abs(box1-box2)<ans)
	ans=abs(box1-box2);
	
	cout<<ans<<endl;
	return 0;
}