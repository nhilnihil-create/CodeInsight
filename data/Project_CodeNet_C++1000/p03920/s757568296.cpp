#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,j=0;
	cin>>n;
	int a[100000];
	if(n>2){
		while(n>0){
			for( i=1;;i++){
				int k = (i*(i+1))/2;
				if(k>=n){
					break;
				}
			}
			n = n-i;
			a[j++] = i;
		}
		for(int k=j-1;k>=0;k--){
			cout<<a[k]<<endl;
		}
	}else{
		cout<<n<<endl;
	}
	return 0;
}