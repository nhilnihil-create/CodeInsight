 
#include<iostream>
using namespace std;
int arr[1000]={};
void primeN(int n){
	int x=n;
	for (int i=2; i<=n; i++){
		while (x%i==0){
			arr[i]++;
			x/=i;
		}
	}
}
int main(){
 
	int N;
	cin>>N;
	
	for (int i=2; i<=N; i++){
		primeN(i);
	}
	
	//for (int i=0; i<=N;i++){
	//	cout << arr[i] << " ";
	//}cout << endl;
	long long x = 1;
	for (int i=0; i<=N; i++){
		x*=(arr[i]+1);
		x%=1000000007;
	}
	cout << x << endl;
}
