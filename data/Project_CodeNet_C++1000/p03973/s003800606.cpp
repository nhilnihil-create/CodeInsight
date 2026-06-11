#include<iostream>
using namespace std;
int main(){
	int n;
	int a,b,c;
	int i,j,k;
	long long int s=0;
	cin>>n;
	b=1;
	for(i=0;i<n;i++){
		cin>>a;
		if(i==0){
			s+=a-1,b=2;
			continue;
		}
		if(a==b)b++;
		else s+=(a-1)/b;
	}
	cout<<s<<endl;
	return 0;
}
