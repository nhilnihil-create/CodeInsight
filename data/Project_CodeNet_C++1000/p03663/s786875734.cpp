#include<iostream>
using namespace std;
int main(){
	int n;
	long long int m[3];
	int i,j,k;
	long long int a,b;
	char c;
	cout<<"? 10000000001"<<endl;
	cin>>c;
	if(c=='Y'){
		a=1;
		for(i=0;i<12;i++){
			cout<<"? "<<a+1<<endl;
			cin>>c;
			if(c=='Y')break;
			a*=10;
		}
		cout<<"! "<<a<<endl;
		return 0;
	}
	a=10;
	for(n=1;;n++,a*=10){
		cout<<"? "<<a<<endl;
		cin>>c;
		if(c=='N')break;
	}
	m[0]=a,m[2]=a*10-1;
	while(1){
		if(m[2]-m[0]<=1)break;
		m[1]=(m[0]+m[2])/2;
		cout<<"? "<<m[1]<<endl;
		cin>>c;
		if(c=='Y')m[2]=m[1];
		else m[0]=m[1];
	}
	m[2]/=10;
	while(m[2]>1000000000){
		m[2]/=10;
	}
	cout<<"! "<<m[2]<<endl;
	return 0;
}
		
