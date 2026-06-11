#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int a[20];
	memset(a,0,sizeof(a));
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		a[x]++;
	}
	for(int i=n;;i++){
		int tp = i;
		while(tp){
			if(a[tp%10]){
				break;
			}
			tp/=10;
		}
		if(tp == 0){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}