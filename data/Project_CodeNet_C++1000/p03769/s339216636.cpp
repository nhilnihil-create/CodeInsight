#include<iostream>

using namespace std;

long long N,M;
int i,j;
long long a[105];
long long b[105];

void solver(long long n){
	if(n==1){
		i++;
		b[i]=M--;
		return ;
	}
	if(n&1) {
		i++;
		b[i]=M--;;
		solver(n>>=1);
		
	}
	else{
		j++;
		a[j]=M--;
		solver(n-1);
	}
}

int main()
{
	long long N;
	cin>>N;
	M=100;
	solver(N);
	cout<<2*(i+j)<<endl;
	for(int m=1;m<=j;m++){
		cout<<a[m]<<" ";
	}
	for(int m=i;m>=1;m--){
		cout<<b[m]<<" ";
	}
	
//	cout<<" ! "<<i<<" ! "<<j<<"!";
	for(int m=101-i-j;m<=100;m++){
		cout<<m<<" ";
	}
	return 0;
}
