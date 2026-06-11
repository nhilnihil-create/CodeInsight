#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>A;
	long long int n,ai,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ai;
		A.push_back(ai);
		sum+=ai;
	}
	int x=sum/n;
	int y=ceil(sum*1.000/n);
	long long int c=0,d=0;
	for(int i=0;i<n;i++){
		c+=pow(A[i]-x,2);
		d+=pow(A[i]-y,2);
	}
	cout<<min(c,d)<<endl;
	
	return 0;
}
