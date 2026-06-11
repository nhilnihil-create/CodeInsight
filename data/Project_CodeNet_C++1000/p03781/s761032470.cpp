#include <iostream>
using namespace std;

int main() {
	long long i=0;
	long long sum=0;
	long long n;
	cin>>n;
	while(sum<n){
		sum=sum+i;
		i++;
	}
	cout<<i-1<<endl;
	return 0;
}