#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
 
typedef long long ll;
const int N = 102;

int n;
int a[N];
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	int mx = 0;
	int mn = n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[x]++;
		mx = max(mx,x);
		mn = min(mn,x);
	}
	
	if(mx &1){
		if(a[(mx+1)/2] != 2){
			cout<<"Impossible";
			return 0;
		}
	}else{
		if(a[mx/2] != 1){
			cout<<"Impossible";
			return 0;
		}
	}
	if(mn < (mx+1)/2){
		cout<<"Impossible";
		return 0;
	}
	
	for(int i=mn+1;i<=mx;i++){
		if(a[i] < 2){
			cout<<"Impossible";
			return 0;
		}
	}
	
	cout<<"Possible";
	
	return 0;
}
