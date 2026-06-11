#include<iostream>
using namespace std;
int main(){
int i,l;
long long m,K,a[50];
cin >> K;
l = K%50;
m = K/50;
cout << 50 << endl;
if(K<=50){
	for(i=0;i<K;i++){
		a[i] = 50;
	}
	for(i=K;i<50;i++){
		a[i] = 0;
	}
}else{
	for(i=0;i<l;i++){
    	a[i] = m+50;
	}
	for(i=l;i<50;i++){
		a[i] = 49 - l + m ;
	}
}
for(i=0;i<50;i++){
cout << a[i] << " " ;
}
cout << endl;
}