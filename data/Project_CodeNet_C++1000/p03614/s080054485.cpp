#include <iostream>
using namespace std;

int main() {
	long n,k=0,l=0;
	cin>>n;
	long p[n];
	for(int i=0;i<n;i++)cin>>p[i];
	for(int i=0;i<n;i++){
		if(p[i]==i+1){
			k++;
			if(i==n-1)l+=(k+1)/2;
		}
		else{
			l+=(k+1)/2;
			k=0;
		}
	}
	cout<<l<<endl;
	return 0;
}