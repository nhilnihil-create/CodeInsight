#include<cstdio>
#include<iostream>
const int N=1e5+5;
using namespace std;
int a[N];
int main(){
	int n;
	cin >> n;
	while(n--){
		int b;
		cin >> b;
		a[b]++;
		a[b-1]++;
		a[b+1]++;
	}
	int max=0;
	for(int i=0;i<N;i++){
		if (a[i]>max){
			max=a[i];
		}
	}
	cout << max;
}