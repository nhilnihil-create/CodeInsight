#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(1001,1);
	
	int x,j;
	for(int i=2;i<=n;i++){
			x=i;
			j=2;
			while(1){
				if(x%j==0){
					x/=j;
					a[j]++;
					if(x<=1)break;
				}else{
					j++;
				}
			}
	}	
	
	long long sum=1;
	for(int i=0;i<=1000;i++){
			sum*=a[i];
			sum=sum%1000000007;
	}
	cout << sum << endl;	
	return 0;
}
