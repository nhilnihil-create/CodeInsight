#include <stdio.h>
#include <iostream>
using namespace std;	
int a[100005] = {0};
int b[100005] = {0};
int main(){
	int i,n;
	cin >> n;
	int tp = 0;
	for(i=0;i<n;i++){
		cin >> a[i];
		if(tp<a[i]){
			tp = a[i];
		}
		b[a[i]]++;
		b[a[i]-1]++;
		b[a[i]+1]++;
	}
	int max = 0;
	for(i=0;i<=tp;i++){
		if(max<b[i]){
			max = b[i];
		}
	}
	cout << max;
	return 0;
}