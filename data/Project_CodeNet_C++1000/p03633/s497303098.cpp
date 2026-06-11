#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

long long GCD(long long a,long long b){
	long long x=max(a,b),y=min(a,b);
	if(x%y==0){
		return y;
	}else{
		return GCD(y,x%y);
	}
}

long long LCM(long long a,long long b){
	return (a/GCD(a,b))*b;
}

int main(){
	int n;
	cin >> n;
	vector<long long> a(n);
	
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	if(n==1){
		cout << a[0] << endl;
		return 0;
	}
	
	long long ans=a[0];
	
	for(int i=1;i<n;i++){
		if(i==1){
			ans=LCM(a[i],a[i-1]);
		}else{
			ans=LCM(a[i],ans);
		}
	}
	cout << ans << endl;
	return 0;
}
