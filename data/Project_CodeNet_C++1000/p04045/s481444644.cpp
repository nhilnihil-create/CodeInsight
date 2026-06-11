#include<iostream>
#include<stdio.h>
#include<cmath> 
using namespace std;
int main(){
    int n,k,i,x;
	int d[10];
	cin >> n >> k;
	for(i=0;i<k;i++){
		cin >> d[i];
	}
	int f=1;
	while(f){
		f=0;
		x=n;
		while(x){
			for(i=0;i<k;i++){
				if(d[i]==x%10){
					f=1;
					break;
				}
			}
			x/=10;
		}
		n++;
	}
	cout << n-1 << endl;
    return 0;
}