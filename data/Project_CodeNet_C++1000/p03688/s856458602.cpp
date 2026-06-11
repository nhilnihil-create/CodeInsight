#include <bits/stdc++.h>
using namespace std;
 
int main(){
	long long int N; 
	cin >> N;
    long long int a[N]; 
    	for(int i=0;i<N;i++){
    	cin >> a[i];
    	}
    long long b = a[0];
    long long c = a[0];
  	for(int i=1;i<N;i++){
    		if(b < a[i]){
			b = a[i];
			}
    		if(c > a[i]){
			c = a[i];
			}
    	}
	if(b-c >= 2){
      	cout << "No" << endl;
    	}
  	if(b == c){
      		if(N >= 2*b){
      		cout << "Yes" << endl;
    		}else if(b == N-1){
      		cout << "Yes" << endl;
    		}else{
            cout << "No" << endl;
            }
    	}
	if(b-c == 1){
		long long x = 0;
        long long y = 0;
        for(int i=0;i<N;i++){
    		if(b == a[i]){
			x = x + 1;
			}
    		if(c == a[i]){
			y = y + 1;
			}
    	}
        if(b > y && x >= 2 * (b-y)){
      		cout << "Yes" << endl;
    	}else{
            cout << "No" << endl;
    	} 
    }
}