#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
int arr[N],sum1[N],sum2[N];
signed main(){
	int a,b;
	cin>>a>>b;
	if(a==b){
		cout<<"0";return 0;
	}
	if(abs(a)==abs(b)){
		cout<<"1";return 0;
	}
	if(a==0){
		if(b>=0) cout<<b-a;else cout<<abs(b)+1;
		return 0;
	}
	if(b==0){
		if(a<=0) cout<<abs(a);
		else cout<<a+1;
		return 0;
	}
	if(a>0&&b>0){
		if(a>b){
			cout<<a-b+2;
		}else{
			cout<<b-a;
		}
		return 0;
	}
	if(a*b<0){
		cout<<abs(abs(a)-abs(b))+1;return 0;
	}
	if(a<0&&b<0){
		if(a>b){
			cout<<abs(a-b)+2;
		}else{
			cout<<abs(a-b);
		}
	} 
	
	return 0;
}
/*
2 -4
4 -2

-4 2
-4  -9
*/