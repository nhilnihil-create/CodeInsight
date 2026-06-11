#include<cstdio>
#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
int main(){
	int N, maxA, minB;
	cin >> N;
	int A[N], B[N];
	for(int i = 0; i < N; i++){
		cin >> A[i] >> B[i];
	}
	maxA = A[0];
	for(int i = 1; i < N; i++){
		if(A[i] > maxA){
			maxA  = A[i];
		}
	}
	minB = B[0];
	for(int i = 1; i < N; i++){
		if(B[i] < minB){
			minB  = B[i];
		}
	}
	cout << maxA +  minB << endl;
	return 0;
}