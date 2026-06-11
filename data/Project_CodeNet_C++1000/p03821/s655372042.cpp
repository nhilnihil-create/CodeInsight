#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long long> a(n),b(n);
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	
	long long p=0;
	
	for(int i=n-1;i>=0;i--){
		a[i]+=p;
		if(a[i]%b[i]==0)continue;
		if(a[i]<b[i]){
			p+=b[i]-a[i];
		}else if(a[i]>b[i]){
			p+=b[i]-a[i]%b[i];
		}
	}
	
	cout << p << endl;	
		
	return 0;
}
