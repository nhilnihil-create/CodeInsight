#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include <string.h>
using namespace std;

int main(){
	long long int i,j,m,n;//1 2 3 4 5  12
	char a,b;
	while(cin>>n){
		long long int sum=0;
		int count=0;
		for(i=1;i<=n;i++){
			sum=sum+i;
			count++;
			if(sum>=n){
				break;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}