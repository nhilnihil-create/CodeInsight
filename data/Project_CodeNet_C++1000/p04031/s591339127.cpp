#include<iostream>
using namespace std;
int main(void){
	int n;
	cin>>n;
	int a[100];
	for(int i(0);i<n;i++){
		cin>>a[i];
	}
	int average_int;
	double average_double;
	int sum(0);
	for(int i(0);i<n;i++){
		sum += a[i];
	}
	average_int = sum/n;
	average_double = (double)sum/n;
	if((average_double - average_int)*10 >= 5)average_int++;
	int ans(0);
	for(int i(0);i<n;i++){
		ans += (a[i]-average_int)*(a[i]-average_int);
	}
	cout<<ans<<endl;
	return 0;
}