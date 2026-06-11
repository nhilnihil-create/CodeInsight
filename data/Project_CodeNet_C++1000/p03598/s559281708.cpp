#include<iostream>
using namespace std;
int main(){
	int n,k,x[100];
	cin >> n >> k;
	int i;
	int sum = 0;
	for(i=0;i<n;i++){
		cin >> x[i];
		if(x[i]<k-x[i]){
			sum+=x[i] * 2;
		}else{
			sum+=(k-x[i])*2;
		}
	}
	cout << sum << endl;
	return 0;
}