//============================================================================
// Name        : d.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n;cin>>n;
	long long a[n][n];
	long long b[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(b[i][j]>b[i][k]+b[k][j]){
					b[i][j]=b[i][k]+b[k][j];
				}
			}
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<b[i][j];
//		}
//		cout<<endl;
//	}
	long long ans=0;
	int flag=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				if(a[i][j]>b[i][j]){
					flag=0;
					break;
				}
				int sumflag=1;
				for(int k=0;k<n;k++){
					if(k!=i&&k!=j){
//						cout<<i<<j<<k<<endl;
						if(b[i][j]==b[i][k]+b[k][j]){
							sumflag=0;
							break;
						}
					}
				}
				if(sumflag){
					ans+=a[i][j];
				}
			}
		}
	}
	if(flag){
		cout<<ans/2<<endl;
	}else{
		cout<<"-1"<<endl;
	}


	return 0;
}