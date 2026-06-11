#include<iostream>
 
using namespace std;

int main(){
	long long int A,B,C;
	long long int sum;
	cin>>A>>B>>C;
	if(A%2==0||B%2==0||C%2==0){cout<<0<<endl;}
	else {
		if(A>=B&&A>=C){
			sum=B*C;
			cout<<sum<<endl;
		}
		else if(B>=A&&B>=C){
			sum=A*C;
			cout<<sum<<endl;
		}
		else if(C>=A&&C>=C){
			sum=A*B;
			cout<<sum<<endl;
		}
	} 
}