#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

const int N=100000;
int a[N]; 

int main(){
	int n;
	cin >> n;
	while(n--){
		int m;
		cin >> m;
		a[m]++;
		a[m-1]++;
		a[m+1]++; 
	} 
	int max=0;
	for(int i=0;i<N;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	cout << max <<endl;
	return 0;
}