#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int i,n,t;
	cin >> n >> t;
	int a[n],b[n],c[n];
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	b[n-1] = a[n-1];
	for(i=0;i<n-1;i++){
		if(a[n-2-i]<b[n-1-i]){
			b[n-2-i] = b[n-1-i];
		}else{
			b[n-2-i] = a[n-2-i];
		}
	}
	
	for(i=0;i<n;i++){
		c[i] = b[i]-a[i];
	}
	sort(c,c+n);
	for(i=0;i<n;i++){
		if(c[i]==c[n-1]){
			cout << n-i << endl;
			return 0;
		}
	}
}
		
	
			
			
		