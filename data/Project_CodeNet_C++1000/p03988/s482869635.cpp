#include<bits/stdc++.h>
using namespace std;

int N, ma, f, a[100], cn[101];

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> a[i];
		if(ma < a[i]) ma = a[i];
	}
	for(int i=0; i<N; i++) cn[a[i]]++;
	if(ma % 2 == 0){
		for(int i=ma; i>ma/2; i--){
			if(cn[i] < 2) f = 1;
		}
		if(cn[ma/2] != 1) f = 1;
		for(int i=0; i<ma/2; i++){
			if(cn[i] > 0) f = 1;
		}
	}else{
		for(int i=ma; i>(ma+1)/2; i--){
			if(cn[i] < 2) f = 1;
		}
		if(cn[(ma+1)/2] != 2) f = 1;
		for(int i=0; i<=ma/2; i++){
			if(cn[i] > 0) f = 1;
		}
	}
	cout << (f?"Impossible":"Possible") << endl;
	return 0;
}
