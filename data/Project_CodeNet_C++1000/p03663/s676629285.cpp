#include<iostream>
#include<string>
using namespace std;

long long pow(long long x,long long n){
	long long re=1;
	for(int i=0;i<n;i++)re*=x;
	return re;
}

int main(){
	int k=0;
	while(k<10){
		cout<<"? "<<pow(10,k+1)<<endl;
		cout.flush();
		string ans;
		cin>>ans;
		if(ans=="N")break;
		k++;
	}
	if(k==10){
		k=0;
		while(k<10){
			cout<<"? "<<2*pow(10,k)<<endl;
			cout.flush();
			string ans;
			cin>>ans;
			if(ans=="Y")break;
			k++;
		}
		cout<<"! "<<pow(10,k)<<endl;
	}
	else{
		long long l=pow(10,k),r=pow(10,k+1)-1;
		while(r-l>0){
			long long m=(r+l)/2;
			cout<<"? "<<10*m<<endl;
			cout.flush();
			string ans;
			cin>>ans;
			if(ans=="Y")r=m;
			else l=m+1;
		}
		cout<<"! "<<r<<endl;
	}
	cout.flush();
}
